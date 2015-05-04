#include "proofdeduction.h"
#include "../Parser/kvantorexist.h"
#include "../Parser/Parser.h"
#include "../Parser/implication.h"
#include "proofcheck.h"
#include "../Parser/kvantorall.h"
#include <algorithm>

using namespace std;

void ProofDeduction::addHeader(std::string str)
{
    clearData();
    size_t breaker = str.find("|-", 0);
    if (breaker == string::npos)
    {
        std::cerr << "Syntax error in proposal" << "\n";
        exit(-1);
    }
    size_t breaker_old = breaker;
    str = ';' + str.substr(0, breaker);
    breaker_old++;
    breaker = str.rfind(';', str.size() - 1);
    proposalStr = str.substr(breaker + 1, breaker_old - breaker - 1);
    proposal = std::shared_ptr<const Expression>(Parser::parseString(proposalStr));
    proposalFreeVariables = proposal->getVariables();
    breaker_old = breaker;
    while (breaker != 0)
    {
        breaker = str.rfind(';', breaker_old - 1);
        assumptions.emplace_back(
                Parser::parseString(
                        str.substr(breaker + 1, breaker_old - breaker - 1)));
        breaker_old = breaker;
    }
    proposalStr = "(" + proposalStr + ")";
}

int ProofDeduction::isAssumption(const Expression *expr)
{
    for (size_t i = 0; i < assumptions.size(); i++)
    {
        if (assumptions[i]->isEqual(expr))
        {
            return (int)i;
        }
    }
    return -1;
}

void ProofDeduction::writeProof(std::shared_ptr<Expression const> now, std::vector<std::shared_ptr<Expression const>> &vout)
{
    if (proofCheck.wasExpression(now) != -1)
    {
        return;
    }
    int num_axiom = proofCheck.isAxiom(now.get());
    int num_arithm_axiom = proofCheck.isArithmAxiom(now.get());
    PredicatResult num_predicat_axiom = proofCheck.isPredicatAxiom(now.get());
    int num_assumpt = isAssumption(now.get());
    PredicatResult num_predicat_rule = proofCheck.getPredicatRule(now.get());
    if (num_axiom != -1 || num_assumpt != -1 || num_arithm_axiom != -1 || num_predicat_axiom.num != -1)
    {
        writeAxiomProof(now, vout);
    }
    else if (proposal->isEqual(now.get()))
    {
        writeSelfProof(vout);
    }
    else if (proofCheck.getModusPones(now.get()).first != (size_t)-1)
    {
        writeMpProof(now, vout);
    }
    else if (num_predicat_rule.num != -1)
    {
//        std::cerr << now->toString() << " " << num_predicat_rule << "\n";
        const Implication* impl = static_cast<const Implication*>(now.get());
        if (typeid(*impl->left.get()) == typeid(KvantorExist))
        {
            writeRuleExistProof(now, vout);
        }
        else
        {
            writeRuleAllProof(now, vout);
        }
    }
    proofCheck.addExpression(now);
    vout.emplace_back(new Implication(proposal, now));

}

void ProofDeduction::writeSelfProof(std::vector<std::shared_ptr<Expression const>> &vout)
{
    string str1 =  proposalStr + "->(" + proposalStr + "->" + proposalStr + ")" + "\n";
    string str2 =
            "(" + proposalStr + "->(" + proposalStr + "->" + proposalStr + ")" + ")"
                    + "->" + "(" + proposalStr + "->" + "((" + proposalStr + "->"  + proposalStr + ")"
                    + "->" + proposalStr + "))" + "->" + "(" + proposalStr + "->" + proposalStr + ")";
    string str3 =
            "(" + proposalStr + "->" + "((" + proposalStr + "->"  + proposalStr + ")"
                    + "->" + proposalStr + "))" + "->" + "(" + proposalStr + "->" + proposalStr + ")";
    string str4 =
            "(" + proposalStr + "->" + "((" + proposalStr + "->"  + proposalStr + ")"
                    + "->" + proposalStr + "))";
    vout.emplace_back(Parser::parseString(str1));
    vout.emplace_back(Parser::parseString(str2));
    vout.emplace_back(Parser::parseString(str3));
    vout.emplace_back(Parser::parseString(str4));
}

void ProofDeduction::writeAxiomProof(std::shared_ptr<Expression const> now, std::vector<std::shared_ptr<Expression const>> &vout)
{
    vout.push_back(now);
    string str1 = "(" + now->toString() + ")" + "->((" +  proposalStr + ")->" + "(" + now->toString() + "))\n";
//    std::cerr << "OK " << str1 << "\n";
    vout.emplace_back(Parser::parseString(str1));
}

void ProofDeduction::writeMpProof(std::shared_ptr<Expression const> now, std::vector<std::shared_ptr<Expression const>> &vout)
{
    // first > second
    std::pair<size_t, size_t> approves = proofCheck.getModusPones(now.get());
//    std::cerr << "M.P." << approves.first << " " << approves.second << "\n";
    const std::string& str = now->toString();
    string m2 = proofCheck.getExpression(approves.first)->toString();
    string m1 = proofCheck.getExpression(approves.second)->toString();
    string str1 =
            "(" +  proposalStr + "->" + m1 + ")"
                    + "->" + "((" + proposalStr + "->" + "(" +  m1 + "->" + str + ")" + ")"
                    + "->" + "(" + proposalStr + "->" + str + "))";
    string str2 =
            "(" + proposalStr + "->(" + m2 + "))"
                    + "->" + "(" + proposalStr + "->" + str + ")";
    vout.emplace_back(Parser::parseString(str1));
    vout.emplace_back(Parser::parseString(str2));
}

void ProofDeduction::clearData()
{
    assumptions.clear();
    proposal.reset();
    proposalStr.clear();
    proofCheck.clearData();
}

bool ProofDeduction::writeProof(const std::string &str, std::vector<std::shared_ptr<const Expression>> &vout)
{
    std::shared_ptr<const Expression> eptr(Parser::parseString(str));
    if (proposal->isEqual(eptr.get()) ||
            isAssumption(eptr.get()) != -1 ||
            proofCheck.isArithmAxiom(eptr.get()) != -1 ||
            proofCheck.isAxiom(eptr.get()) != -1 || proofCheck.getModusPones(eptr.get()).first != (size_t)-1)
    {
        writeProof(eptr, vout);
        return true;
    }
    PredicatResult aPredicat = proofCheck.isPredicatAxiom(eptr.get());
    if (aPredicat.num != -1)
    {
        if (aPredicat.error)
        {
            errstr = "Терм " + aPredicat.notFreeTerm->toString() +
                    " не свободен для подстановки в " + aPredicat.formula->toString() + "\n";
            return false;
        }
        if (std::find(proposalFreeVariables.begin(), proposalFreeVariables.end(), aPredicat.varName)
                != proposalFreeVariables.end())
        {
            errstr = "Используется схема аксиом с квантором по переменной "
                    + aPredicat.varName + " входящей свободно в допущение" + proposalStr + "\n";
            return false;
        }
        writeProof(eptr, vout);
        return true;
    }
    PredicatResult rPredicat = proofCheck.getPredicatRule(eptr.get());
    if (rPredicat.num != -1)
    {
        if (rPredicat.error)
        {
            // правило вывода, входит свободно в часть
            errstr = "Переменная "
                    + rPredicat.varName + " входит свободно в формулу " + rPredicat.formula->toString() + "\n";
            return false;
        }
        if (std::find(proposalFreeVariables.begin(), proposalFreeVariables.end(), rPredicat.varName)
                != proposalFreeVariables.end())
        {
            errstr = "Используется правило вывода с квантором по переменной "
                    + rPredicat.varName + " входящей свободно в допущение" + proposalStr + "\n";
            return false;
        }
        writeProof(eptr, vout);
        return true;
    }
    std::cerr << "Proofment to nepravil'noe" << "\n";
    std::cerr << eptr->toString() << "\n";
    return false;
}

void ProofDeduction::writeRuleExistProof(std::shared_ptr<Expression const> now, std::vector<std::shared_ptr<Expression const>> &vout)
{
    const Implication* impl = static_cast<const Implication*>(now.get());
    std::string B = static_cast<const KvantorExist*>(impl->left.get())->term->toString();
    std::string C = impl->right->toString();
    const std::string& A = this->proposalStr;
    ProofDeduction pd1;
    std::vector<std::shared_ptr<const Expression>> vnow;
    pd1.addHeader(A + "->" + B + "->" + C + ";"
            + B + ";" + A + "|-" + C);
    pd1.writeProof(A + "->" + B + "->" + C, vnow);
    pd1.writeProof(A, vnow);
    pd1.writeProof(B + "->" + C, vnow);
    pd1.writeProof(B, vnow);
    pd1.writeProof(C, vnow);
    pd1.clearData();
    pd1.addHeader(A + "->" + B + "->" + C + ";"
            + B + "|-" + A + "->" + C);
    for (auto item : vnow)
    {
        pd1.writeProof(item, vout);
    }
    pd1.clearData();
    vnow.clear();
    B = static_cast<const KvantorExist*>(impl->left.get())->toString();
    vout.emplace_back(Parser::parseString(B + "->" + A + "->" + C));
    pd1.addHeader(B + "->" + A + "->" + C + ";"
            + A + ";" + B + "|-" + C);
    pd1.writeProof(B + "->" + A + "->" + C, vnow);
    pd1.writeProof(B, vnow);
    pd1.writeProof(A + "->" + C, vnow);
    pd1.writeProof(A, vnow);
    pd1.writeProof(C, vnow);
    pd1.clearData();
    pd1.addHeader(B + "->" + A + "->" + C + ";"
            + A + "|-" + B + "->" + C);
    for (auto item : vnow)
    {
        pd1.writeProof(item, vout);
    }
}

void ProofDeduction::writeRuleAllProof(std::shared_ptr<Expression const> now, std::vector<std::shared_ptr<Expression const>> &vout)
{
    const Implication* impl = static_cast<const Implication*>(now.get());
    std::string B = impl->left->toString();
    std::string C = static_cast<const KvantorAll*>(impl->right.get())->term->toString();
//    std::cerr << "Assumpt " << (assumptions.size() > 0 ? assumptions[0]->toString() : "no") << "\n";
//    std::cerr << "Rule " << now->toString() << "\n";
//    std::cerr << "Term " << C << "\n";
    ProofDeduction pd1 = ProofDeduction();
    const std::string A = proposalStr;
    std::string AaB = "(" + A + "&" + B + ")";
    pd1.addHeader(A + "->" + B + "->" + C + ";" +
            AaB + "|-" + C);
    pd1.writeProof(AaB + "->" + A, vout);
    pd1.writeProof(AaB + "->" + B, vout);
    pd1.writeProof(AaB, vout);
    pd1.writeProof(A, vout);
    pd1.writeProof(B, vout);
    pd1.writeProof(A + "->" + B + "->" + C, vout);
    pd1.writeProof(B + "->" + C, vout);
    pd1.writeProof(C, vout);
    C = impl->right->toString();
    vout.emplace_back(new Implication(Parser::parseString(AaB), impl->right));
    std::vector<std::shared_ptr<const Expression>> vnow;
    ProofDeduction pd2 = ProofDeduction();
    pd2.addHeader(AaB + "->" + C + ";"
            + A + ";"
            + B + "|-"
            + C);
    pd2.writeProof(A + "->" + B + "->" + AaB, vnow);
    pd2.writeProof(A, vnow);
    pd2.writeProof(B, vnow);
    pd2.writeProof(B + "->" + AaB, vnow);
    pd2.writeProof(AaB, vnow);
    pd2.writeProof(AaB + "->" + C, vnow);
    pd2.writeProof(C, vnow);
    pd2.clearData();
    pd2.addHeader(AaB + "->" + C + ";"
            + A + "|-"
            + B + "->" + C);
    for (auto item : vnow)
    {
        pd2.writeProof(item, vout);
    }
}

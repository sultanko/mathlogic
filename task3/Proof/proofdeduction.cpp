#include "proofdeduction.h"
#include "../Parser/Parser.h"
#include "../Parser/implication.h"
#include "proofcheck.h"

using namespace std;

void ProofDeduction::addHeader(std::string str)
{
    size_t breaker = str.find('|', 0);
    size_t breaker_old = breaker;
    str = ',' + str.substr(0, breaker);
    breaker_old++;
    breaker = str.rfind(',', str.size() - 1);
    proposalStr = str.substr(breaker + 1, breaker_old - breaker - 1);
    proposal = std::shared_ptr<const Expression>(Parser::parseString(proposalStr));
    breaker_old = breaker;
    while (breaker != 0)
    {
        breaker = str.rfind(',', breaker_old - 1);
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
            return i;
        }
    }
    return -1;
}

void ProofDeduction::writeProof(std::shared_ptr<Expression const> now, std::vector<std::shared_ptr<Expression const>> &vout)
{
    if (proofCheck.wasExpression(now))
    {
        return;
    }
    proofCheck.addExpression(now);
    int num_axiom = proofCheck.isAxiom(now.get());
    int num_assumpt = isAssumption(now.get());
    if (num_axiom != -1 || num_assumpt != -1)
    {
        writeAxiomProof(now, vout);
    }
    else if (proposal->isEqual(now.get()))
    {
        writeSelfProof(vout);
    }
    else
    {
        writeMpProof(now, vout);
    }
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
    proofCheck.clearData();
}

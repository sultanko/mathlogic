#include "proofgenerate.h"
#include <string>
#include "../Parser/Parser.h"
#include "../Parser/implication.h"
#include "../Parser/variable.h"
#include "../Parser/negation.h"

using namespace std;

std::string ProofGenerate::excludeThird[] = {
        "!A->(A|!A)",
        "(((!A)->(A|!A)))->(((!A)->(A|!A)))->(((!A)->(A|!A)))",
        "((((!A)->(A|!A)))->(((!A)->(A|!A)))->(((!A)->(A|!A))))->((((!A)->(A|!A)))->((((!A)->(A|!A)))->(((!A)->(A|!A))))->(((!A)->(A|!A))))->(((!A)->(A|!A)))->(((!A)->(A|!A)))",
        "((((!A)->(A|!A)))->((((!A)->(A|!A)))->(((!A)->(A|!A))))->(((!A)->(A|!A))))->(((!A)->(A|!A)))->(((!A)->(A|!A)))",
        "((((!A)->(A|!A)))->((((!A)->(A|!A)))->(((!A)->(A|!A))))->(((!A)->(A|!A))))",
        "(((!A)->(A|!A)))->(((!A)->(A|!A)))",
        "(((!A)->(A|!A))->((!A)->!(A|!A))->!(!A))",
        "(((!A)->(A|!A))->((!A)->!(A|!A))->!(!A))->(((!A)->(A|!A)))->(((!A)->(A|!A))->((!A)->!(A|!A))->!(!A))",
        "(((!A)->(A|!A)))->(((!A)->(A|!A))->((!A)->!(A|!A))->!(!A))",
        "((((!A)->(A|!A)))->((!A)->(A|!A)))->((((!A)->(A|!A)))->((!A)->(A|!A))->(((!A)->!(A|!A))->!(!A)))->(((!A)->(A|!A)))->(((!A)->!(A|!A))->!(!A))",
        "((((!A)->(A|!A)))->((!A)->(A|!A))->(((!A)->!(A|!A))->!(!A)))->(((!A)->(A|!A)))->(((!A)->!(A|!A))->!(!A))",
        "(((!A)->(A|!A)))->(((!A)->!(A|!A))->!(!A))",
        "((!(A|!A)->((!A)->!(A|!A))) ->(!(A|!A)->((!A)->!(A|!A))->!(!A))->(!(A|!A)->!(!A)))",
        "((!(A|!A)->((!A)->!(A|!A))) ->(!(A|!A)->((!A)->!(A|!A))->!(!A))->(!(A|!A)->!(!A)))->(((!A)->(A|!A)))->((!(A|!A)->((!A)->!(A|!A))) ->(!(A|!A)->((!A)->!(A|!A))->!(!A))->(!(A|!A)->!(!A)))",
        "(((!A)->(A|!A)))->((!(A|!A)->((!A)->!(A|!A))) ->(!(A|!A)->((!A)->!(A|!A))->!(!A))->(!(A|!A)->!(!A)))",
        "(!(A|!A)->(!A)->!(A|!A))",
        "(!(A|!A)->(!A)->!(A|!A))->(((!A)->(A|!A)))->(!(A|!A)->(!A)->!(A|!A))",
        "(((!A)->(A|!A)))->(!(A|!A)->(!A)->!(A|!A))",
        "((((!A)->(A|!A)))->(!(A|!A)->(!A)->!(A|!A)))->((((!A)->(A|!A)))->(!(A|!A)->(!A)->!(A|!A))->((!(A|!A)->((!A)->!(A|!A))->!(!A))->(!(A|!A)->!(!A))))->(((!A)->(A|!A)))->((!(A|!A)->((!A)->!(A|!A))->!(!A))->(!(A|!A)->!(!A)))",
        "((((!A)->(A|!A)))->(!(A|!A)->(!A)->!(A|!A))->((!(A|!A)->((!A)->!(A|!A))->!(!A))->(!(A|!A)->!(!A))))->(((!A)->(A|!A)))->((!(A|!A)->((!A)->!(A|!A))->!(!A))->(!(A|!A)->!(!A)))",
        "(((!A)->(A|!A)))->((!(A|!A)->((!A)->!(A|!A))->!(!A))->(!(A|!A)->!(!A)))",
        "((((!A)->!(A|!A))->!(!A))->!(A|!A)->(((!A)->!(A|!A))->!(!A)))",
        "((((!A)->!(A|!A))->!(!A))->!(A|!A)->(((!A)->!(A|!A))->!(!A)))->(((!A)->(A|!A)))->((((!A)->!(A|!A))->!(!A))->!(A|!A)->(((!A)->!(A|!A))->!(!A)))",
        "(((!A)->(A|!A)))->((((!A)->!(A|!A))->!(!A))->!(A|!A)->(((!A)->!(A|!A))->!(!A)))",
        "((((!A)->(A|!A)))->(((!A)->!(A|!A))->!(!A)))->((((!A)->(A|!A)))->(((!A)->!(A|!A))->!(!A))->(!(A|!A)->(((!A)->!(A|!A))->!(!A))))->(((!A)->(A|!A)))->(!(A|!A)->(((!A)->!(A|!A))->!(!A)))",
        "((((!A)->(A|!A)))->(((!A)->!(A|!A))->!(!A))->(!(A|!A)->(((!A)->!(A|!A))->!(!A))))->(((!A)->(A|!A)))->(!(A|!A)->(((!A)->!(A|!A))->!(!A)))",
        "(((!A)->(A|!A)))->(!(A|!A)->(((!A)->!(A|!A))->!(!A)))",
        "((((!A)->(A|!A)))->(!(A|!A)->(((!A)->!(A|!A))->!(!A))))->((((!A)->(A|!A)))->(!(A|!A)->(((!A)->!(A|!A))->!(!A)))->(!(A|!A)->!(!A)))->(((!A)->(A|!A)))->(!(A|!A)->!(!A))",
        "((((!A)->(A|!A)))->(!(A|!A)->(((!A)->!(A|!A))->!(!A)))->(!(A|!A)->!(!A)))->(((!A)->(A|!A)))->(!(A|!A)->!(!A))",
        "(((!A)->(A|!A)))->(!(A|!A)->!(!A))",
        "(!(A|!A))->!!A",
        "A->(A|!A)",
        "((A->(A|!A)))->((A->(A|!A)))->((A->(A|!A)))",
        "(((A->(A|!A)))->((A->(A|!A)))->((A->(A|!A))))->(((A->(A|!A)))->(((A->(A|!A)))->((A->(A|!A))))->((A->(A|!A))))->((A->(A|!A)))->((A->(A|!A)))",
        "(((A->(A|!A)))->(((A->(A|!A)))->((A->(A|!A))))->((A->(A|!A))))->((A->(A|!A)))->((A->(A|!A)))",
        "(((A->(A|!A)))->(((A->(A|!A)))->((A->(A|!A))))->((A->(A|!A))))",
        "((A->(A|!A)))->((A->(A|!A)))",
        "((A->(A|!A))->(A->!(A|!A))->!A)",
        "((A->(A|!A))->(A->!(A|!A))->!A)->((A->(A|!A)))->((A->(A|!A))->(A->!(A|!A))->!A)",
        "((A->(A|!A)))->((A->(A|!A))->(A->!(A|!A))->!A)",
        "(((A->(A|!A)))->(A->(A|!A)))->(((A->(A|!A)))->(A->(A|!A))->((A->!(A|!A))->!A))->((A->(A|!A)))->((A->!(A|!A))->!A)",
        "(((A->(A|!A)))->(A->(A|!A))->((A->!(A|!A))->!A))->((A->(A|!A)))->((A->!(A|!A))->!A)",
        "((A->(A|!A)))->((A->!(A|!A))->!A)",
        "((!(A|!A)->(A->!(A|!A))) ->(!(A|!A)->(A->!(A|!A))->!A)->(!(A|!A)->!A))",
        "((!(A|!A)->(A->!(A|!A))) ->(!(A|!A)->(A->!(A|!A))->!A)->(!(A|!A)->!A))->((A->(A|!A)))->((!(A|!A)->(A->!(A|!A))) ->(!(A|!A)->(A->!(A|!A))->!A)->(!(A|!A)->!A))",
        "((A->(A|!A)))->((!(A|!A)->(A->!(A|!A))) ->(!(A|!A)->(A->!(A|!A))->!A)->(!(A|!A)->!A))",
        "(!(A|!A)->A->!(A|!A))",
        "(!(A|!A)->A->!(A|!A))->((A->(A|!A)))->(!(A|!A)->A->!(A|!A))",
        "((A->(A|!A)))->(!(A|!A)->A->!(A|!A))",
        "(((A->(A|!A)))->(!(A|!A)->A->!(A|!A)))->(((A->(A|!A)))->(!(A|!A)->A->!(A|!A))->((!(A|!A)->(A->!(A|!A))->!A)->(!(A|!A)->!A)))->((A->(A|!A)))->((!(A|!A)->(A->!(A|!A))->!A)->(!(A|!A)->!A))",
        "(((A->(A|!A)))->(!(A|!A)->A->!(A|!A))->((!(A|!A)->(A->!(A|!A))->!A)->(!(A|!A)->!A)))->((A->(A|!A)))->((!(A|!A)->(A->!(A|!A))->!A)->(!(A|!A)->!A))",
        "((A->(A|!A)))->((!(A|!A)->(A->!(A|!A))->!A)->(!(A|!A)->!A))",
        "(((A->!(A|!A))->!A)->!(A|!A)->((A->!(A|!A))->!A))",
        "(((A->!(A|!A))->!A)->!(A|!A)->((A->!(A|!A))->!A))->((A->(A|!A)))->(((A->!(A|!A))->!A)->!(A|!A)->((A->!(A|!A))->!A))",
        "((A->(A|!A)))->(((A->!(A|!A))->!A)->!(A|!A)->((A->!(A|!A))->!A))",
        "(((A->(A|!A)))->((A->!(A|!A))->!A))->(((A->(A|!A)))->((A->!(A|!A))->!A)->(!(A|!A)->((A->!(A|!A))->!A)))->((A->(A|!A)))->(!(A|!A)->((A->!(A|!A))->!A))",
        "(((A->(A|!A)))->((A->!(A|!A))->!A)->(!(A|!A)->((A->!(A|!A))->!A)))->((A->(A|!A)))->(!(A|!A)->((A->!(A|!A))->!A))",
        "((A->(A|!A)))->(!(A|!A)->((A->!(A|!A))->!A))",
        "(((A->(A|!A)))->(!(A|!A)->((A->!(A|!A))->!A)))->(((A->(A|!A)))->(!(A|!A)->((A->!(A|!A))->!A))->(!(A|!A)->!A))->((A->(A|!A)))->(!(A|!A)->!A)",
        "(((A->(A|!A)))->(!(A|!A)->((A->!(A|!A))->!A))->(!(A|!A)->!A))->((A->(A|!A)))->(!(A|!A)->!A)",
        "((A->(A|!A)))->(!(A|!A)->!A)",
        "(!(A|!A))->!A",
        "((!(A|!A))->!A)->(!(A|!A)->!(!A))->(!!(A|!A))",
        "(!(A|!A)->!(!A))->!(!(A|!A))",
        "!(!(A|!A))",
        "!!(A|!A)->(A|!A)",
        "A|!A"
};

void ProofGenerate::proofThis(std::string str)
{
    statement = shared_ptr<const Expression>(Parser::parseString(str));
    vector<string> variablesName = statement->getVariables();
    varValues.clear();
    for (auto var : variablesName)
    {
        varValues[var] = true;
    }
    bool res = checkTavtologi(varValues.begin());
    if (!res)
    {
        cout << "Высказывание ложно при";
        auto itb = varValues.begin();
        cout << " " << itb->first << "=" << (itb->second ? "И" : "Л");
        itb++;
        for (;itb != varValues.end(); itb++)
        {
            cout << ", " << itb->first << "=" << (itb->second ? "И" : "Л");
        }
        cout << "\n";
        return;
    }
    writeProof();
//    cout << str << "\n";
}

bool ProofGenerate::checkTavtologi(std::map<std::string, bool>::iterator it)
{
    if (it == varValues.end())
    {
        return statement->calculate(varValues);
    }
    std::map<std::string, bool>::iterator it2 = it;
    it2++;
    it->second = true;
    if (!checkTavtologi(it2))
    {
        return false;
    }
    it->second = false;
    return (checkTavtologi(it2));
}

void ProofGenerate::writeProof()
{
    writeProofParts(varValues.begin());
    while (!varValues.empty())
    {
        const std::string varName = varValues.begin()->first;
        auto itBlock = blocks.begin();
        for (; itBlock != blocks.end(); itBlock++)
        {
            if (itBlock->first.find(varName) != itBlock->first.end())
            {
                break;
            }
        }
        if (itBlock == blocks.end())
        {
            varValues.erase(varName);
        }
        else
        {
            auto itBlockNeg = findNegate(itBlock,varName);
            variableProof(varName, *itBlock);
            variableProof(varName, *itBlockNeg);

            vector<shared_ptr<const Expression>> res;
            map<string, bool> varVal(itBlock->first.begin(), itBlock->first.end());
            res.reserve(itBlock->second.size() + itBlockNeg->second.size());
            res.insert(res.end(), itBlock->second.begin(), itBlock->second.end());
            res.insert(res.end(), itBlockNeg->second.begin(), itBlockNeg->second.end());

            writeExcludeThird(res, varName);

            size_t pos1 = (size_t) (itBlock - blocks.begin());
            size_t pos2 = (size_t) (itBlockNeg - blocks.begin());
            blocks.erase(blocks.begin() + pos1);
            blocks.erase(blocks.begin() + pos2 + (pos1 < pos2 ? -1 : 0));

            blocks.emplace_back(varVal, res);
        }
    }
    for (auto block : blocks.begin()->second)
    {
        cout << block->toString() << "\n";
    }
}

void ProofGenerate::writeProofParts(std::map<std::string, bool>::iterator it)
{
    if (it == varValues.end())
    {
        proofItem item;
        item.first = varValues;
        statement->proofThis(item.second, varValues);
        blocks.push_back(item);
        return;
    }
    std::map<std::string, bool>::iterator it2 = it;
    it2++;
    it->second = true;
    writeProofParts(it2);
    it->second = false;
    writeProofParts(it2);
}

void ProofGenerate::variableProof(std::string varName, ProofGenerate::proofItem &vin)
{
    proofDeduction.clearData();
    if (vin.first[varName])
    {
        proofDeduction.setProposal(make_shared<const Variable>(varName));
    }
    else
    {
        proofDeduction.setProposal(std::shared_ptr<const Expression>(new Negation(new Variable(varName))));
    }
    for (auto varVal : vin.first)
    {
        if (varVal.first != varName)
        {
            if (varVal.second)
            {
                proofDeduction.addAssumption(new Variable(varVal.first));
            }
            else
            {
                proofDeduction.addAssumption(new Negation(new Variable(varVal.first)));
            }
        }
    }
    vector<shared_ptr<const Expression>> vout;
    for (auto expr : vin.second)
    {
        proofDeduction.writeProof(expr, vout);
    }
    vin.second.assign(vout.begin(), vout.end());
    vin.first.erase(varName);
}

ProofGenerate::blockIter ProofGenerate::findNegate(ProofGenerate::blockIter itBlock, std::string varName)
{
    auto itBlockNeg = blocks.begin();
    for (; itBlockNeg != blocks.end(); itBlockNeg++)
    {
        bool ok = true;
        for (auto item : itBlockNeg->first)
        {
            if ((item.first != varName && item.second != itBlock->first[item.first])
                    || (item.first == varName && item.second == itBlock->first[item.first] ))
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            break;
        }
    }
    return itBlockNeg;
}

void ProofGenerate::writeExcludeThird(vector<std::shared_ptr<Expression const>> &vout, std::string varName)
{
    const size_t sizeExclude = extent<decltype(excludeThird)>::value;
    for (size_t i = 0; i < sizeExclude; i++)
    {
        size_t index = 0;
        while (true)
        {
            index = excludeThird[i].find("A", index);
            if(index == string::npos)
            {
                break;
            }
            excludeThird[i].replace(index, 1, varName);
            index += varName.length();
        }
        vout.emplace_back(Parser::parseString(excludeThird[i]));
        index = 0;
        while (true)
        {
            index = excludeThird[i].find(varName, index);
            if(index == string::npos)
            {
                break;
            }
            excludeThird[i].replace(index, varName.length(), "A");
            index += 1;
        }
    }
    string pr[4];
    pr[0] = "(P->(A))->(!P->(A))->((P|!P)->(A))";
    pr[1] = "(!P->(A))->((P|!P)->(A))";
    pr[2] = "(P|!P)->(A)";
    pr[3] = "A";
    map<string, shared_ptr<const Expression>> prMap;
    prMap["P"] = shared_ptr<const Expression>(new Variable(varName));
    prMap["A"] = statement;
    for (size_t i = 0; i < 4; i++)
    {
        std::shared_ptr<const Expression> prStr(Parser::parseString(pr[i]));
        vout.emplace_back(prStr->substitute(prMap));
    }
}

#include <iostream>
#include <cstring>

#include "Parser/ParserUtils.h"
#include "Parser/ExpressionUtils.h"

using namespace std;

#define FILENAME "task2"

char strAxiom[1024];

int main()
{
    freopen(FILENAME".in", "r", stdin);
    freopen(FILENAME".out", "w", stdout);
    size_t counter = 0;
    string statement;
    getline(cin, statement);
    ExpressionUtils::getInstance()->addHeader(statement);
    while ( cin.getline(strAxiom, 1024))
    {
        counter++;
        string str(strAxiom, strlen(strAxiom));
//        cout << ParserUtils::parseString(str)->toString() << "\n" << "\n" << "\n";
        const Expression* now = ParserUtils::parseString(str);
        ExpressionUtils::getInstance()->addExpression(now);
        int num_axiom = ExpressionUtils::getInstance()->isAxiom(now);
        int num_assumpt = ExpressionUtils::getInstance()->isAssumption(now);
        if (num_axiom != -1 || num_assumpt != -1)
        {
            cout << str << "\n";
            cout << str << "->(" <<  ExpressionUtils::getInstance()->getProposalString() << "->" << str << ")\n";
        }
        else if (ExpressionUtils::getInstance()->getProposal()->isEqual(now))
        {
            ExpressionUtils::getInstance()->writeSelfProof();
        }
        else
        {
            std::pair<size_t, size_t> approves = (ExpressionUtils::getInstance()->getModusPones(now));
            const std::string& prStr = ExpressionUtils::getInstance()->getProposalString();
            std::string m1 = ExpressionUtils::getInstance()->getExpressions()[approves.first]->toString();
            std::string m2 = ExpressionUtils::getInstance()->getExpressions()[approves.second]->toString();
            cout << "(" <<  prStr << "->" << m1 << ")"
                << "->" << "(" << prStr << "->" << "(" <<  m2 << ")" << ")"
                << "->" << "(" << prStr << "->" << str << ")"
                << "\n";
            cout
                    << "(" << prStr << "->(" << m2 << "))"
                    << "->" << "(" << prStr << "->" << str << ")"
                    << "\n";
        }
        cout << ExpressionUtils::getInstance()->getProposalString() << "->(" << str << ")\n";
//        cout << "OK " << counter << "\n";
    }
    return 0;
}
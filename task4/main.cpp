#include <iostream>

#include "Proof/proofgenerate.h"
#include "Parser/Parser.h"

using namespace std;

#define FILENAME "task4"

char strAxiom[2024];

int main()
{
    freopen(FILENAME".in", "r", stdin);
    freopen(FILENAME".out", "w", stdout);
    string statement;
    getline(cin, statement);
    ProofDeduction::getInstance()->addHeader(statement);
    std::vector<std::shared_ptr<const Expression>> vout;
    while (getline(cin, statement))
    {
//        std::cerr << "Main " << statement << "\n";
        if (!ProofDeduction::getInstance()->writeProof(statement, vout))
        {
            std::cerr << "Smth going wrong\n";
            std::cerr << statement << "\n";
            std::cout << "Error\n";
            return 0;
        }
        for (auto item : vout)
        {
            std::cout << item->toString() << "\n";
        }
        vout.clear();
    }
    return 0;
}
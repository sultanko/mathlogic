#include <iostream>

#include "Proof/proofgenerate.h"
#include "Parser/Parser.h"

using namespace std;

#define FILENAME "shd/incorrect11"

char strAxiom[2024];

int main()
{
    freopen(FILENAME ".in", "r", stdin);
    freopen(FILENAME ".out", "w", stdout);
    std::ios::sync_with_stdio(false);
    string statement;
    getline(cin, statement);
    ProofDeduction::getInstance()->addHeader(statement);
    std::vector<std::shared_ptr<const Expression>> vout;
    int counter = 0;
    while (getline(cin, statement))
    {
//        std::cerr << "Main " << statement << "\n";
        if (!ProofDeduction::getInstance()->writeProof(statement, vout))
        {
            std::cerr << "Smth wrong with " << statement << "\n";
            std::cout << "Вывод некорректен начиная с формулы номер " << counter << "\n";
            std::cout << ProofDeduction::getInstance()->getErrstr() << "\n";
            return 0;
        }
        counter++;
    }
    for (auto item : vout)
    {
        std::cout << item->toString() << "\n";
    }
    return 0;
}
#include <iostream>
#include <cstring>

#include "ParserUtils.h"
#include "ExpressionUtils.h"

using namespace std;

#define FILENAME "axiom"

char strAxiom[5024];

int main()
{
    freopen(FILENAME".in", "r", stdin);
//    freopen("maxtest1.in", "r", stdin);
    freopen(FILENAME".out", "w", stdout);
    size_t counter = 0;
    while (cin.getline(strAxiom, 5024))
    {
        counter++;
        string str(strAxiom, strlen(strAxiom));
//        cout << ParserUtils::parseString(str)->toString() << "\n" << "\n" << "\n";
        const Expression* now = ParserUtils::parseString(str);
        ExpressionUtils::getInstance()->addExpression(now);
        int num_axiom = ExpressionUtils::getInstance()->isAxiom(now);
        cout << "(" << counter << ") " << str;
        if (num_axiom != -1)
        {
            cout << " (" << "Сх. акс. " << num_axiom + 1 << ")\n";
        }
        else
        {
            std::pair<size_t, size_t> approves = (ExpressionUtils::getInstance()->getModusPones(now));
            if (approves.first != -1)
            {
                cout << " (" << "M.P. " << approves.first + 1 << "," << approves.second + 1 << ")\n";
            }
            else
            {
                cout << " (" << "Не доказано" << ")" << "\n";
                exit(-1);
            }
        }
    }
    return 0;
}
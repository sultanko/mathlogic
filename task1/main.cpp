#include <iostream>
#include <cstring>
#include <cstdlib>

#include "ParserUtils.h"
#include "ExpressionUtils.h"

using namespace std;

#define FILENAME "shd/good5"

int main()
{
    freopen(FILENAME".in", "r", stdin);
//    freopen("maxtest1.in", "r", stdin);
    freopen(FILENAME".out", "w", stdout);
    std::ios::sync_with_stdio(false);
    size_t counter = 0;
    string str;
    while (getline(cin, str))
    {
        counter++;
//        cout << ParserUtils::parseString(str)->toString() << "\n" << "\n" << "\n";
        const Expression* now = ParserUtils::parseString(str);
        int num_axiom = ExpressionUtils::getInstance()->isAxiom(now);
        cout << "(" << counter << ") " << str;
        if (num_axiom != -1)
        {
            cout << " (" << "Сх. акс. " << num_axiom + 1 << ")\n";
        }
        else
        {
            std::pair<size_t, size_t> approves = (ExpressionUtils::getInstance()->getModusPones(now));
            if (approves.first != (size_t)-1)
            {
                cout << " (" << "M.P. " << approves.second + 1 << "," << approves.first + 1 << ")\n";
            }
            else
            {
                cout << " (" << "Не доказано" << ")" << "\n";
                return -1;
            }
        }
        ExpressionUtils::getInstance()->addExpression(now);
    }
    return 0;
}
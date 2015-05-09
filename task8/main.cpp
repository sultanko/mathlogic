#include <iostream>
#include "Parser/Parser.h"
#include "Parser/CNF.h"

using namespace std;

#define TFILE "../tests/equal7.in"
#define FILE "input.txt"

int main()
{
    freopen(FILE, "r", stdin);
    freopen("output.txt", "w", stdout);
    string expression;
    getline(cin, expression);
    size_t eq1 = expression.find("=", 0);
    auto expr1 = Parser::parseString(expression.substr(0, eq1));
    auto expr2 = Parser::parseString(expression.substr(eq1 + 1, expression.size() - eq1 - 1));
    try
    {
        auto c1 = CNF::exprToCNF(expr1);
        auto c2 = CNF::exprToCNF(expr2);
        cout << ((c1 == c2) ? "Equals" : "Not Equals") << "\n";
        cerr << "Compare: " << c1->compare(c2) << "\n";
//        cerr << "First: " <<  c1 << "\n";
//        cerr << "Second: " << c2 << "\n";
    } catch (std::runtime_error e) {
        std::cerr << e.what() << "\n";
        exit(-1);
    }
    return 0;
}
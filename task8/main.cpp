#include <iostream>
#include "Parser/Parser.h"
#include "Parser/CNF.h"

using namespace std;

int main()
{
    freopen("task8.in", "r", stdin);
    freopen("task8.out", "w", stdout);
    string expression;
    getline(cin, expression);
    size_t eq1 = expression.find("=", 0);
    auto expr1 = Parser::parseString(expression.substr(0, eq1));
    auto expr2 = Parser::parseString(expression.substr(eq1 + 1, expression.size() - eq1 - 1));
//    cerr << "Parsed" << "\n";
    auto c1 = CNF::exprToCNF(expr1);
//    cerr << "First" << "\n";
    auto c2 = CNF::exprToCNF(expr2);
//    cerr << "Second" << "\n";
//    cout << expr1->toString() << "=" << expr2->toString() << "\n";
    cout << ((c1 == c2) ? "Equals" : "Not Equals") << "\n";
    cerr << ((c1 == c2) ? "Equals" : "Not Equals") << "\n";
    return 0;
}
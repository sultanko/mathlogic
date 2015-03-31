#include <iostream>
#include <cstring>

#include "Parser/ParserUtils.h"
#include "Parser/ExpressionUtils.h"

using namespace std;

#define FILENAME "shd/contra2"

int main()
{
    freopen(FILENAME".in", "r", stdin);
    freopen(FILENAME".out", "w", stdout);
    std::ios::sync_with_stdio(false);
    size_t counter = 0;
    string str;
    getline(cin, str);
    ExpressionUtils::getInstance()->addHeader(str);
    while (getline(cin, str))
    {
        counter++;
//        cerr << "OK " << "axiom" << "\n";
        const Expression* now = ParserUtils::parseString(str);
        ExpressionUtils::getInstance()->writeProof(now);
//        cerr << "OK " << counter << "\n";
    }
    return 0;
}
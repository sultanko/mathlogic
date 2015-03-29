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
//        cerr << "OK " << "axiom" << "\n";
        const Expression* now = ParserUtils::parseString(str);
        ExpressionUtils::getInstance()->writeProof(now);
//        cerr << "OK " << counter << "\n";
    }
    return 0;
}
#include <iostream>
#include <stdio.h>

#include "Parser/Parser.h"
#include "Kripke/Generator.h"

using namespace std;

#define FILENAME "task5"

int main()
{
    freopen(FILENAME ".in", "r", stdin);
    freopen(FILENAME ".out", "w", stdout);
//    std::ios::sync_with_stdio(false);
    string statement;
    char str[1024];
//    int countAxioms;
//    scanf("%d%*c", &countAxioms);
//    while (countAxioms > 0)
//    {
//        countAxioms--;
    cin.getline(str, 1024);
    statement = str;
    if (statement.empty())
    {
        return 0;
    }
    Expression *expression = Parser::parseString(statement);
    Generator generator = Generator();
    generator.generateWorlds(expression);
    generator.generateTrees();
//        cerr << "Genearated\n";
//        cerr << generator.getTrees().size() << "\n";

    const map<size_t, bool> result = generator.checkExpression(expression);
    if (result.empty())
    {
        cerr << statement << "\n";
        cerr << "ALL OK" << "\n";
        cout << "Формула общезначима" << "\n";
    }
    else
    {
        cerr << statement << "\n";
        cerr << "FIND CONTRMODEL" << "\n";
//        cout << statement << "\n";
        generator.getTrees().front()->printTree(cout, result, 0);
//            cout << *generator.getTrees().front().get() << "\n";
    }
//    }
    return 0;
}
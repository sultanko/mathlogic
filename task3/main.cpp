#include <iostream>
#include <cstring>

#include "Proof/proofgenerate.h"

using namespace std;

#define FILENAME "task3"

char strAxiom[1024];

int main()
{
    freopen(FILENAME".in", "r", stdin);
    freopen(FILENAME".out", "w", stdout);
    string statement;
    getline(cin, statement);
    ProofGenerate::getInstanse()->proofThis(statement);
    return 0;
}
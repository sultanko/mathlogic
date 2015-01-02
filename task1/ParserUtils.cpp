#include "ParserUtils.h"
#include <algorithm>
#include "negation.h"
#include "disjunction.h"
#include "conjunction.h"
#include "implication.h"
#include "variable.h"

using namespace std;


State ParserUtils::getTerm(size_t curPos)
{
    if (str[curPos] >= 'A' && str[curPos] <= 'Z')
    {
        size_t startPos = curPos;
        curPos++;
        while (str[curPos] >= '0' && str[curPos] <= '9')
        {
            curPos++;
        }
        return State(new Variable(str.substr(startPos, curPos - startPos)), curPos);
    }
    else if (str[curPos] == '!')
    {
        State nextTerm = getTerm(curPos + 1);
        return State(new Negation(nextTerm.result), nextTerm.index);
    }
/*    if (str[curPos] == '-')
    {
        return getExpression(curPos + 2);
    }*/
    return getExpression(curPos + 1);
}

State ParserUtils::getConjuction(size_t curPos)
{
    State result = getTerm(curPos);
    curPos = result.index;
    while (curPos < str.size()
            && str[curPos] == '&')
    {
        State term = getTerm(curPos + 1);
        curPos = term.index;
        result.result = new Conjunction(result.result, term.result);
    }
    result.index = curPos;
    return result;
}

State ParserUtils::getDisjunction(size_t curPos)
{
    State result = getConjuction(curPos);
    curPos = result.index;
    while (curPos < str.size()
            && str[curPos] == '|')
    {
        State term = getConjuction(curPos + 1);
        curPos = term.index;
        result.result = new Disjunction(result.result, term.result);
    }
    result.index = curPos;
    return result;

}

State ParserUtils::getImplication(size_t curPos)
{
    State result = getDisjunction(curPos);
    curPos = result.index;
    while (curPos < str.size()
            && str[curPos] == '-')
    {
        State term = getImplication(curPos + 2);
        curPos = term.index;
        result.result = new Implication(result.result, term.result);
    }
    result.index = curPos;
    return result;
}

State ParserUtils::getExpression(size_t curPos)
{
    State result = getImplication(curPos);
    if (result.index < str.size() && str[result.index] == ')')
    {
        result.index++;
    }
//    std::cerr << result.index << "\n";
    return result;
}


Expression* ParserUtils::parseString(string str)
{
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    ParserUtils::str = str;
    Expression* res = getExpression(0).result;
    return res;
}

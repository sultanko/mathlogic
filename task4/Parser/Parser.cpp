#include "Parser.h"
#include <algorithm>
#include "negation.h"
#include "disjunction.h"
#include "conjunction.h"
#include "implication.h"
#include "variable.h"
#include "kvantorall.h"
#include "kvantorexist.h"
#include "equality.h"
#include "addition.h"
#include "multiplication.h"
#include "predicat.h"
#include "Zero.h"
#include "functionmy.h"
#include "Shtrix.h"

using namespace std;

State Parser::getMultiplied(size_t curPos)
{
    State result(nullptr, 0);
//    std::cerr << "Mul " <<  curPos << " " << str[curPos] << "\n";
    if (str[curPos] == '(')
    {
        result = getTerm(curPos + 1);
        result.index++;
    }
    else if (str[curPos] == '0')
    {
        curPos++;
        result = State(new Zero(), curPos);
    }
    else if (str[curPos] >= 'a' && str[curPos] <= 'z')
    {
        size_t startPos = curPos;
        curPos++;
        while (str[curPos] >= '0' && str[curPos] <= '9')
        {
            curPos++;
        }
        if (str[curPos] != '(')
        {
            result = State(new Variable(str.substr(startPos, curPos - startPos)), curPos);
        }
        else
        {
            size_t endPos = curPos;
            std::vector<std::shared_ptr<const Expression>> terms;
            if (str[curPos] == '(')
            {
                while (str[curPos] != ')')
                {
                    State term = getTerm(curPos + 1);
                    curPos = term.index;
                    terms.emplace_back(term.result);
                }
                curPos++;
            }
            result = State(new FunctionMy(str.substr(startPos, endPos - startPos), terms), curPos);
        }
    }
    curPos = result.index;
    while (curPos < str.size() && str[curPos] == '\'') {
        curPos++;
        result = State(new Shtrix(result.result), curPos);
    }
    return result;
}

State Parser::getSummand(size_t curPos)
{
    State result = getMultiplied(curPos);
    curPos = result.index;
    while (curPos < str.size()
            && str[curPos] == '*')
    {
        State term = getMultiplied(curPos + 1);
        curPos = term.index;
        result.result = new Multiplication(result.result, term.result);
    }
    result.index = curPos;
    return result;
}

State Parser::getTerm(size_t curPos)
{
    State result = getSummand(curPos);
    curPos = result.index;
    while (curPos < str.size()
            && str[curPos] == '+')
    {
        State term = getSummand(curPos + 1);
        curPos = term.index;
        result.result = new Addition(result.result, term.result);
    }
//    if (curPos < str.size() && str[curPos] == ')') {
//        curPos++;
//    }
//    std::cerr << curPos << " " << str[curPos] << "\n";
    result.index = curPos;
    return result;
}
State Parser::getVariable(size_t curPos)
{
    size_t startPos = curPos;
    curPos++;
    while (str[curPos] >= '0' && str[curPos] <= '9')
    {
        curPos++;
    }
    return State(new Variable(str.substr(startPos, curPos - startPos)), curPos);
}

State Parser::getPredicat(size_t curPos)
{
    if (str[curPos] >= 'A' && str[curPos] <= 'Z') {
        size_t startPos = curPos;
        curPos++;
        while (str[curPos] >= '0' && str[curPos] <= '9') {
            curPos++;
        }
        size_t endPos = curPos;
        std::vector<std::shared_ptr<const Expression>> terms;
        if (str[curPos] == '(') {
            while (curPos < str.size() && str[curPos] != ')') {
                State term = getTerm(curPos + 1);
                curPos = term.index;
                terms.emplace_back(term.result);
            }
            curPos++;
        }
        return State(new Predicat(str.substr(startPos, endPos - startPos), terms), curPos);
    }
    State left = getTerm(curPos);
    State right = getTerm(left.index + 1);
    return State(new Equality(left.result, right.result), right.index);
}

bool Parser::isPredicate(size_t curPos)
{
    int balance = 0;
    size_t breaker = str.find("=", curPos);
    if (breaker == std::string::npos)
    {
        return false;
    }
    for (size_t i = curPos; i < breaker; i++)
    {
        if (str[i] == '(')
        {
            balance++;
        }
        else if (str[i] == ')')
        {
            balance--;
            if (balance < 0)
            {
                return false;
            }
        }
    }
    return balance == 0;
}

State Parser::getUnarnoe(size_t curPos)
{
    if (str[curPos] == '(')
    {
        if (isPredicate(curPos))
        {
            return getPredicat(curPos);
        }
        else
        {
            State res = getExpression(curPos + 1);
            res.index++;
            return res;
        }
    }
    if (str[curPos] == '!')
    {
        State nextTerm = getUnarnoe(curPos + 1);
        return State(new Negation(nextTerm.result), nextTerm.index);
    }
    if (str[curPos] == '@' || str[curPos] == '?')
    {
        char kvantor = str[curPos];
        State variable = getVariable(curPos + 1);
        State nextTerm = getUnarnoe(variable.index);
        if (kvantor == '@') {
            return State(new KvantorAll(variable.result, nextTerm.result), nextTerm.index);
        } else {
            return State(new KvantorExist(variable.result, nextTerm.result), nextTerm.index);
        }
    }
    return getPredicat(curPos);
}

State Parser::getConjuction(size_t curPos)
{
    State result = getUnarnoe(curPos);
    curPos = result.index;
    while (curPos < str.size()
            && str[curPos] == '&')
    {
        State term = getUnarnoe(curPos + 1);
        curPos = term.index;
        result.result = new Conjunction(result.result, term.result);
    }
    result.index = curPos;
    return result;
}

State Parser::getDisjunction(size_t curPos)
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

State Parser::getImplication(size_t curPos)
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

State Parser::getExpression(size_t curPos)
{
    State result = getImplication(curPos);
//    if (result.index < str.size() && str[result.index] == ')')
//    {
//        result.index++;
//    }
//    std::cerr << result.index << "\n";
    return result;
}


Expression*Parser::parseString(string str)
{
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    Parser::str = str;
    Expression* res = getExpression(0).result;
    return res;
}


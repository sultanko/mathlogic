#ifndef PARSER_UTILS_H_
#define PARSER_UTILS_H_

#include "Expression.h"
#include <string>

struct State {
    Expression* result;
    size_t index;

    State(Expression* res, size_t index)
            : result(res),
              index(index)
    {

    }
};

namespace Parser
{

//public:
    Expression* parseString(std::string str);

//private:
    State getMultiplied(size_t curPos);
    State getSummand(size_t curPos);
    State getTerm(size_t curPos);
    State getPredicat(size_t curPos);
    State getVariable(size_t curPos);
    State getUnarnoe(size_t curPos);
    State getConjuction(size_t curPos);
    State getDisjunction(size_t curPos);
    State getImplication(size_t curPos);
    State getExpression(size_t curPos);
    bool isPredicate(size_t curPos);

//private:
    static std::string str;
};

#endif

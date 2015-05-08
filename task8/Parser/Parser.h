//
// Created by sultan on 07.05.15.
//

#ifndef TASK8_PARSER_H
#define TASK8_PARSER_H


#include "Expression.h"

class Parser
{
private:
    struct State
    {
        State(size_t i, const std::shared_ptr<const Expression>& shared_ptr)
        : pos(i), result(shared_ptr)
        {}

        size_t pos;
        std::shared_ptr<const Expression> result;
    };

    static State getAtom(const std::string& str, size_t pos);
    static State getSummand(const std::string& str, size_t pos);
    static State getMultiplier(const std::string& str, size_t pos);
    static State getPower(const std::string& str, size_t pos);
    static State getExpression(const std::string& str, size_t pos);
public:
    static std::shared_ptr<const Expression> parseString(const std::string& str);

};


#endif //TASK8_PARSER_H

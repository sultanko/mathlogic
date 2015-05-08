//
// Created by sultan on 07.05.15.
//

#include "Parser.h"

Parser::State Parser::getAtom(const std::string &str, size_t pos)
{
    if (str[pos] == '(') {
        return getExpression(str, pos + 1);
    }
    size_t count = 0;
    if (str[pos] == 'w')
    {
        return State(pos + count,
                     std::shared_ptr<const Expression>(
                             new Expression("w")));
    }
    while (pos < str.size() && std::isdigit(str[pos + count]))
    {
        count++;
    }
    return State(pos + count, std::shared_ptr<const Expression>(
            new Expression(str.substr(pos, count))));
}

Parser::State Parser::getPower(const std::string &str, size_t pos)
{
    State cur = getAtom(str, pos);
    while (cur.pos < str.size() && str[cur.pos] == '^')
    {
        State temp = getPower(str, cur.pos + 1);
        cur.pos = temp.pos;
        cur.result = std::shared_ptr<const Expression>(new Expression(cur.result, temp.result, "^"));
    }
    return cur;
}

Parser::State Parser::getMultiplier(const std::string &str, size_t pos)
{
    State cur = getPower(str, pos);
    while (cur.pos < str.size() && str[cur.pos] == '*')
    {
        State temp = getPower(str, cur.pos + 1);
        cur.pos = temp.pos;
        cur.result = std::shared_ptr<const Expression>(new Expression(cur.result, temp.result, "*"));
    }
    return cur;
}

Parser::State Parser::getSummand(const std::string &str, size_t pos)
{
    State cur = getMultiplier(str, pos);
    while (cur.pos < str.size() && str[cur.pos] == '+')
    {
        State temp = getMultiplier(str, cur.pos + 1);
        cur.pos = temp.pos;
        cur.result = std::shared_ptr<const Expression>(new Expression(cur.result, temp.result, "+"));
    }
    return cur;
}

Parser::State Parser::getExpression(const std::string &str, size_t pos)
{
    State cur = getSummand(str, pos);
    if (cur.pos < str.size() && str[cur.pos] == ')')
    {
        cur.pos++;
    }
    return cur;
}

std::shared_ptr<const Expression> Parser::parseString(const std::string &str)
{
    return getExpression(str, 0).result;
}


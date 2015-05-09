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
        return State(pos + 1,
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

std::string trim(const std::string& str,
                 const std::string& whitespace = " \t")
{
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return ""; // no content

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}

std::string reduce(const std::string& str,
                   const std::string& fill = " ",
                   const std::string& whitespace = " \t")
{
    // trim first
    auto result = trim(str, whitespace);

    // replace sub ranges
    auto beginSpace = result.find_first_of(whitespace);
    while (beginSpace != std::string::npos)
    {
        const auto endSpace = result.find_first_not_of(whitespace, beginSpace);
        const auto range = endSpace - beginSpace;

        result.replace(beginSpace, range, fill);

        const auto newStart = beginSpace + fill.length();
        beginSpace = result.find_first_of(whitespace, newStart);
    }

    return result;
}

std::shared_ptr<const Expression> Parser::parseString(const std::string &str)
{
    std::string str2 = reduce(str, "");
//    std::cerr << str2 << "\n";
    return getExpression(str2, 0).result;
}


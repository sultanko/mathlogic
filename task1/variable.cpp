#include "variable.h"
#include "ExpressionUtils.h"


Variable::Variable(std::string str)
    : Expression(str)
{
}

Variable::Variable(char param)
        : Expression(std::string(1, param))
{
}

bool Variable::isSubstitute(const Expression *expr) const
{
    ExpressionUtils* utils = ExpressionUtils::getInstance();
    if (utils->variables.find(stringExpr[0]) == utils->variables.end())
    {
        utils->variables[stringExpr[0]] = expr->getHash();
    }
    else
    {
        if (utils->variables[stringExpr[0]] != expr->getHash())
        {
            return false;
        }
    }
    return true;
}

bool Variable::isEqual(const Expression *expr) const
{
    return false;
}

std::string Variable::toString() const
{
    return stringExpr;
}

std::size_t Variable::getHash() const
{
    std::hash<std::string> hash_fn;
    return hash_fn(stringExpr);
}


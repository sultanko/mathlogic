#include "variable.h"
#include "negation.h"


Variable::Variable(std::string str)
    : Expression(str)
{
    hash = std::hash<std::string>()(stringExpr);
}

Variable::Variable(char param)
        : Expression(std::string(1, param))
{
    hash = std::hash<std::string>()(stringExpr);
}

bool Variable::isSubstitute(const Expression *expr) const
{
//    ProofCheck * utils = ProofCheck::getInstance();
//    if (utils->variables.find(stringExpr) == utils->variables.end())
//    {
//        utils->variables[stringExpr] = expr->getHash();
//    }
//    else
//    {
//        if (utils->variables[stringExpr] != expr->getHash())
//        {
//            return false;
//        }
//    }
    return true;
}

bool Variable::isEqual(const Expression *expr) const
{
    return typeid(*expr) == typeid(Variable)
            && stringExpr == static_cast<const Variable*>(expr)->stringExpr;
}

std::string Variable::toString() const
{
    return stringExpr;
}


bool Variable::calculate(const std::map<std::string, bool> &variables) const
{
    bool ok = variables.find(stringExpr)->second;
    return ok;
}

std::vector<std::string> Variable::getVariables() const
{
    std::vector<std::string> vector1;
    vector1.push_back(stringExpr);
    return vector1;
}

std::shared_ptr<const Expression> Variable::substitute(std::map<std::string, std::shared_ptr<Expression const> > &comparasion) const
{
    auto pointer = comparasion[stringExpr];
    return pointer;
}

void Variable::proofThis(std::vector<std::shared_ptr<const Expression> > &vout, const std::map<std::string, bool> &varValues) const
{
}

bool Variable::calculate(const Tree &tree, const std::map<size_t, bool>& used) const
{
    return tree.containsKey(stringExpr);
}

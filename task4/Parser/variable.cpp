#include "variable.h"
#include "../Proof/proofcheck.h"


Variable::Variable(std::string str)
    : Expression(str)
{
//    hash = (long long) std::hash<std::string>()(stringExpr);
    hash_string = std::hash<std::string>()(toString());
}

Variable::Variable(char param)
        : Expression(std::string(1, param))
{
//    hash = (long long) std::hash<std::string>()(stringExpr);
    hash_string = std::hash<std::string>()(toString());
}

bool Variable::isSubstitute(const Expression *expr) const
{
    ProofCheck * utils = ProofCheck::getInstance();
    if (utils->variables.find(stringExpr) == utils->variables.end())
    {
        utils->variables[stringExpr] = expr;
    }
    else
    {
        if (utils->variables[stringExpr]->getHash() != expr->getHash())
        {
//            std::cerr << "BEDA " << stringExpr << " " << expr->toString() << "\n";
            return false;
        }
    }
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
    auto pointer = comparasion.find(stringExpr);
    if (pointer == comparasion.end())
    {
        return std::shared_ptr<const Expression>(new Variable(stringExpr));
    }
    return pointer->second;
}

void Variable::proofThis(std::vector<std::shared_ptr<const Expression> > &vout, const std::map<std::string, bool> &varValues) const
{
}

SubstState Variable::isFreeToSubstitute(const std::string &varName, const std::vector<std::string> &freeVariables) const
{
    return SubstState(stringExpr == varName);
}

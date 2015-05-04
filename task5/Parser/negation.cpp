#include <iostream>
#include "negation.h"
#include "Parser.h"

std::string Negation::toString() const
{
    return "!" + expr->toString() + "";
}

bool Negation::isEqual(const Expression *expr) const
{
    return typeid(*expr) == typeid(Negation)
            && this->expr->isEqual((static_cast<const Negation*>(expr))->expr.get())
            ;
}

bool Negation::isSubstitute(const Expression *expr) const
{
    if (typeid(*this) != typeid(*expr))
    {
        return false;
    }
    return this->expr->isSubstitute(static_cast<const Negation*>(expr)->expr.get());
}

bool Negation::calculate(const std::map<std::string, bool> &variables) const
{
    return !expr->calculate(variables);
}

std::vector<std::string> Negation::getVariables() const
{
    return expr->getVariables();
}

std::shared_ptr<const Expression> Negation::substitute(std::map<std::string, std::shared_ptr<Expression const> > &comparasion) const
{
    return std::shared_ptr<Expression const>(new Negation(expr->substitute(comparasion)));
}

const std::string Negation::proofment0[] = {
        "!A"
};

const std::string Negation::proofment1[] = {
        "A",
        "(!A->A)->(!A->!A)->!!A",
        "A->!A->A",
        "!A->A",
        "(!A->!A)->!!A",
        "!A->!A->!A",
        "(!A->!A->!A)->(!A->(!A->!A)->!A)->(!A->!A)",
        "(!A->(!A->!A)->!A)->(!A->!A)",
        "!A->(!A->!A)->!A",
        "!A->!A",
        "!!A"
};
void Negation::proofThis(std::vector<std::shared_ptr<const Expression> > &vout, const std::map<std::string, bool> &varValues) const
{
    expr->proofThis(vout, varValues);
    bool res = expr->calculate(varValues);
    if (!res)
    {
        vout.emplace_back(new Negation(expr));
        return;
    }
    const std::string* mas = proofment1;
    const size_t proofSize = std::extent<decltype(proofment1)>::value;
    std::map<std::string, std::shared_ptr<const Expression> > compMap;
    compMap["A"] = expr;
//    std::cerr << "Binary proof A:" << left->toString() << " B: " << right->toString() << "\n";
    for (size_t i = 0; i < proofSize; i++)
    {
        std::shared_ptr<const Expression> now(Parser::parseString(mas[i]));
        vout.emplace_back(now->substitute(compMap));
    }
}

bool Negation::calculateTrueExpr(const Tree &tree, const Expression *expression, const std::map<size_t, bool> &used) const
{
    if (expression->calculate(tree, used))
    {
        return false;
    }
    for (auto item : tree.getTrees())
    {
        if (used.find(item->getId())->second && !calculateTrueExpr(*item.get(), expression, used))
        {
            return false;
        }
    }
    return true;
}

bool Negation::calculate(const Tree &tree, const std::map<size_t, bool> &used) const
{
//    std::cerr << "Neg: " << toString() << " Size: " << tree.getWorld().getForced().size() <<
//    " Res: " << calculateTrueExpr(tree, expr.get()) << "\n";
    return calculateTrueExpr(tree, expr.get(), used);
}

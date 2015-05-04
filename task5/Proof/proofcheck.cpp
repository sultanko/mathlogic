#include "proofcheck.h"
#include "../Parser/implication.h"
#include "../Parser/Parser.h"

std::map<std::string, size_t> ProofCheck::variables;

ProofCheck::ProofCheck()
        : stringAxioms(
        {
                "A->B->A",
                "(A->B)->(A->B->C)->(A->C)",
                "A->B->A&B",
                "A&B->A",
                "A&B->B",
                "A->A|B",
                "B->A|B",
                "(A->C)->(B->C)->(A|B->C)",
                "(A->B)->(A->!B)->!A",
                "!!A->A"
        })
{
    for (size_t i = 0; i < axioms_size; i++)
    {
        axioms.emplace_back(Parser::parseString(stringAxioms[i]));
    }
}

int ProofCheck::isAxiom(const Expression *expr)
{
    for (size_t i = 0; i < axioms_size; i++)
    {
        ProofCheck::variables.clear();
        if (axioms[i]->isSubstitute(expr))
        {
            return (int) i;
        }
    }
    return -1;
}

void ProofCheck::addExpression(std::shared_ptr<const Expression> expr)
{
    expressions.emplace_back(expr);
    hashmap.insert(std::pair<const Expression*, size_t>(expr.get(), expressions.size() - 1));
}


void ProofCheck::addExpression(const Expression *expr)
{
    addExpression(std::shared_ptr<const Expression>(expr));
}

std::pair<size_t, size_t> ProofCheck::getModusPones(const Expression *expr)
{
    for (size_t i = 0; i < expressions.size(); i++)
    {
        const Expression* approve = expressions[i].get();
        if (typeid(*approve) == typeid(Implication))
        {
            const Implication* implication = static_cast<const Implication*>(approve);
            if (implication->right->getHash() == expr->getHash() && implication->right->isEqual(expr))
            {
                auto mit = hashmap.find(implication->left.get());
                if (mit != hashmap.end())
                {
                    return std::make_pair(i, mit->second);
                }
            }
        }
    }
    return std::make_pair(-1, -1);
}

void ProofCheck::clearData()
{
    expressions.clear();
    hashmap.clear();
    variables.clear();
}

std::shared_ptr<const Expression> &ProofCheck::getExpression(size_t i)
{
    return expressions[i];
}

bool ProofCheck::wasExpression(std::shared_ptr<const Expression> expr)
{
    return (hashmap.find(expr.get()) != hashmap.end());
}

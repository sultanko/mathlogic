#include "BinaryExpression.h"
#include "Parser.h"

std::string BinaryExpression::toString() const
{
    return
            "(" +
            left->toString() + stringExpr + right->toString()
            + ")"
            ;
}

BinaryExpression::~BinaryExpression()
{
}

bool BinaryExpression::calculate(const std::map<std::string, bool> &variables) const
{
    return calculate(left->calculate(variables), right->calculate(variables));
}

std::vector<std::string> BinaryExpression::getVariables() const
{
    std::vector<std::string> vec1 = left->getVariables();
    std::vector<std::string> vec2 = right->getVariables();
    vec1.insert(vec1.end(), vec2.begin(), vec2.end());
    return vec1;
}

void BinaryExpression::proofThis(std::vector<std::shared_ptr<const Expression> > &vout, const std::map<std::string, bool> &varValues) const
{
    left->proofThis(vout, varValues);
    right->proofThis(vout, varValues);
    int l1 = left->calculate(varValues) ? 1 : 0;
    int r1 = right->calculate(varValues) ? 1 : 0;
    const std::string* mas = getSimpleProofment(l1, r1);
    const size_t proofSize = getSimpleProofSize(l1, r1);
    std::map<std::string, std::shared_ptr<const Expression> > compMap;
    compMap["A"] = left;
    compMap["B"] = right;
//    std::cerr << "Binary proof A:" << left->toString() << " B: " << right->toString() << "\n";
    for (size_t i = 0; i < proofSize; i++)
    {
        std::shared_ptr<const Expression> now(Parser::parseString(mas[i]));
        vout.emplace_back(now->substitute(compMap));
    }
}

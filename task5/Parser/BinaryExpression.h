#ifndef BINARY_EXPRESSION_H_
#define BINARY_EXPRESSION_H_

#include "Expression.h"

class BinaryExpression : public Expression
{
public:
    std::shared_ptr<const Expression> left;
    std::shared_ptr<const Expression> right;

public:
    template <typename T1, typename T2>
    BinaryExpression(T1 expr1, T2 expr2, const std::string& str)
    :   Expression(str), left(expr1), right(expr2)
    {
        hash = left->getHash() * (ExpressionConsts::BASE_HASH + 32) +
                + std::hash<std::string>()(stringExpr) * 37 +
                right->getHash();
    };

    std::string toString() const;

    virtual bool calculate(const std::map<std::string, bool> &variables) const override;
    virtual bool calculate(bool result1, bool result2) const = 0;

    virtual std::vector<std::string> getVariables() const override;

    virtual void proofThis(std::vector<std::shared_ptr<const Expression> > &vout, const std::map<std::string, bool> &varValues) const override;
    virtual const std::string* getSimpleProofment(int l1, int r1) const = 0 ;
    virtual size_t getSimpleProofSize(int l1, int r1) const = 0;

    virtual ~BinaryExpression();
};

#endif

#ifndef MULTIPLICATION_H_
#define MULTIPLICATION_H_

#include "BinaryExpression.h"

class Multiplication : public BinaryExpression
{

public:
    template <typename T1, typename T2>
    Multiplication(T1 expr1, T2 expr2) : BinaryExpression(expr1, expr2, "*") {}

    virtual std::shared_ptr<const Expression> substitute(std::map<std::string, std::shared_ptr<Expression const> > &comparasion) const override;

    virtual bool calculate(bool result1, bool result2) const;

    virtual const std::string* getSimpleProofment(int l1, int r1) const;
    virtual size_t getSimpleProofSize(int l1, int r1) const;
};
#endif

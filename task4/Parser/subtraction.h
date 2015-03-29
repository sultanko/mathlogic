#ifndef SUBTRACTION_H_
#define SUBTRACTION_H_

#include "BinaryExpression.h"

class Subtraction : public BinaryExpression
{

public:
    template <typename T1, typename T2>
    Subtraction(T1 expr1, T2 expr2) : BinaryExpression(expr1, expr2, "-") {}

public:
    virtual bool calculate(bool result1, bool result2) const override;

    virtual std::shared_ptr<const Expression> substitute(std::map<std::string, std::shared_ptr<Expression const> > &comparasion) const override;
    virtual const std::string *getSimpleProofment(int l1, int r1) const override;

    virtual size_t getSimpleProofSize(int l1, int r1) const override;

};
#endif

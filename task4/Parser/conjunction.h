#ifndef CONJUNCTION_H
#define CONJUNCTION_H

#include "BinaryExpression.h"

class Conjunction : public BinaryExpression
{
public:
    virtual bool calculate(bool result1, bool result2) const override;

    template <typename T1, typename T2>
    Conjunction(T1 expr1, T2 expr2)
    :   BinaryExpression(expr1, expr2, "&")
    {};

    virtual bool isSubstitute(const Expression *expr) const override;

    virtual std::shared_ptr<const Expression> substitute(std::map<std::string, std::shared_ptr<Expression const> > &comparasion) const override;

    virtual bool isEqual(const Expression *expr) const override;

    virtual size_t getSimpleProofSize(int l1, int r1) const override;

    virtual std::string const *getSimpleProofment(int l1, int r1) const override;

public:
    static const std::string proofment0[];
    static const std::string proofment1[];
    static const std::string proofment2[];
    static const std::string proofment3[];
    static const std::string* proofment[2][2];
};

#endif // CONJUNCTION_H

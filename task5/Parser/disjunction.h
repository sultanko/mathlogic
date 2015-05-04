#ifndef DISJUNCTION_H
#define DISJUNCTION_H

#include "BinaryExpression.h"

class Disjunction : public BinaryExpression
{
public:
    virtual bool calculate(bool result1, bool result2) const override;

    template <typename T1, typename T2>
    Disjunction(T1 expr1, T2 expr2)
    :   BinaryExpression(expr1, expr2, "|")
    {};

    virtual bool isSubstitute(const Expression *expr) const override;

    virtual std::shared_ptr<const Expression> substitute(std::map<std::string, std::shared_ptr<Expression const> > &comparasion) const override;

    virtual bool isEqual(const Expression *expr) const override;

    virtual size_t getSimpleProofSize(int l1, int r1) const override;

    virtual const std::string* getSimpleProofment(int l1, int r1) const override;


    virtual bool calculate(const Tree &tree, const std::map<size_t, bool> &used) const override;

public:
    static const std::string proofment0[];
    static const std::string proofment1[];
    static const std::string proofment2[];
    static const std::string proofment3[];
    static const std::string* proofment[2][2];
};

#endif // DISJUNCTION_H

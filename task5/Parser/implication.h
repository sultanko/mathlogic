#ifndef IMPLICATION_H
#define IMPLICATION_H

#include <dirent.h>
#include "BinaryExpression.h"

class Implication : public BinaryExpression
{
public:

    template <typename T1, typename T2>
    Implication(T1 expr1, T2 expr2)
    :   BinaryExpression(expr1, expr2, "->")
    {};

    virtual bool isSubstitute(const Expression *expr) const override;

    virtual bool calculate(bool result1, bool result2) const override;

    virtual std::shared_ptr<const Expression> substitute(std::map<std::string, std::shared_ptr<Expression const> > &comparasion) const override;

    virtual bool isEqual(const Expression *expr) const override;


    virtual size_t getSimpleProofSize(int l1, int r1) const override;

    virtual std::string const *getSimpleProofment(int l1, int r1) const override;


    virtual bool calculate(const Tree &tree, std::map<size_t, bool> const &used) const override;
    bool checkTrueBoth(const Tree &tree, const Expression *expr1, const Expression *expr2,
                                    const std::map<size_t, bool> &used) const;

public:
    static const std::string proofment0[];
    static const std::string proofment1[];
    static const std::string proofment2[];
    static const std::string proofment3[];
    static const std::string* proofment[2][2];

};

#endif // IMPLICATION_H

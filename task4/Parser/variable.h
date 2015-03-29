#ifndef VARIABLE_H
#define VARIABLE_H

#include "unaryexpression.h"
#include <string>
#include <iostream>

class Variable : public Expression
{
public:
    Variable(std::string str);

    Variable(char param);

    virtual bool isSubstitute(const Expression *expr) const;

    virtual bool isEqual(const Expression *expr) const;

    virtual std::string toString() const override;

    virtual std::vector<std::string> getVariables() const override;


    virtual std::shared_ptr<const Expression> substitute(std::map<std::string, std::shared_ptr<Expression const> > &comparasion) const override;

    virtual bool calculate(const std::map<std::string, bool> &variables) const override;

    virtual void proofThis(std::vector<std::shared_ptr<const Expression> > &vout, const std::map<std::string, bool> &varValues) const override;
    virtual SubstState isFreeToSubstitute(const std::string &varName, const std::vector<std::string> &freeVariables) const override;
};

#endif // VARIABLE_H

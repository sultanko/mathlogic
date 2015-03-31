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
};

#endif // VARIABLE_H

//
// Created by sultan on 26.03.15.
//

#ifndef _TASK4_FARGUMENTS_H_
#define _TASK4_FARGUMENTS_H_


#include "Expression.h"

class FArguments : public Expression
{
protected:
    std::vector<std::shared_ptr<const Expression>> terms;

public:
    FArguments(std::string const &stringExpr, std::vector<std::shared_ptr<const Expression>> terms)
            : Expression(stringExpr), terms(terms)
    {
        hash_string = std::hash<std::string>()(toString());
    }


    virtual std::string toString() const override;

    virtual bool isEqual(const Expression *expr) const override;

    virtual bool isSubstitute(const Expression *expr) const override;

    virtual std::vector<std::string> getVariables() const override;

    virtual SubstState isFreeToSubstitute(const std::string &varName, const std::vector<std::string> &freeVariables) const override;


};



#endif //_TASK4_FARGUMENTS_H_

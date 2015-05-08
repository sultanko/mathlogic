//
// Created by sultan on 07.05.15.
//

#ifndef TASK8_EXPRESSION_H
#define TASK8_EXPRESSION_H


#include <string>
#include <vector>
#include <iostream>
#include <memory>

class Expression
{
public:
    enum ExprType {
        Multiplication,
        Addiction,
        Power,
        Variable,
        Number
    };

private:
    std::shared_ptr<const Expression> left;
    std::shared_ptr<const Expression> right;
    const std::string op;
    ExprType exprType;
public:
    Expression(const std::shared_ptr<const Expression>& left,
                const std::shared_ptr<const Expression>& right,
                const std::string& oper);
    Expression(const std::string& oper);
    const std::string& getOperator() const;

    std::shared_ptr<Expression const> const &getLeft() const
    {
        return left;
    }

    std::shared_ptr<Expression const> const &getRight() const
    {
        return right;
    }

    bool isVariable() const;
    std::string toString() const;

    virtual ~Expression();

};


#endif //TASK8_EXPRESSION_H

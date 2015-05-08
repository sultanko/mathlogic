//
// Created by sultan on 07.05.15.
//

#include "Expression.h"

Expression::~Expression()
{

}

const std::string &Expression::getOperator() const
{
    return op;
}

bool Expression::isVariable() const
{
    return (left.get() == nullptr && right.get() == nullptr);
}

std::string Expression::toString() const
{
    if (isVariable())
    {
        return op;
    }
    if (right == nullptr)
    {
        return op + left->toString();
    }
    return "(" + left->toString() + op + right->toString() + ")";
}

Expression::Expression(const std::shared_ptr<const Expression> &left, const std::shared_ptr<const Expression> &right,
                       const std::string &oper)
    : left(left), right(right), op(oper)
{
    if (op == "+") {
        exprType = Addiction;
    } else if (op == "*") {
        exprType = Multiplication;
    } else if (op == "^") {
        exprType = Power;
    } else if (op == "w") {
        exprType = Variable;
    } else {
        exprType = Number;
    }
}

Expression::Expression(const std::string &oper)
    : left(), right(), op(oper)
{
    if (op == "w")  {
        exprType = Variable;
    } else {
        exprType = Number;
    }
}

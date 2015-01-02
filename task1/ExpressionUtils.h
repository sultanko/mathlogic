#ifndef EXPRESSION_UTILS_H_
#define EXPRESSION_UTILS_H_

#include <typeinfo>
#include <string>
#include "Expression.h"
#include <vector>
#include <map>

class ExpressionUtils
{
private:
    static const size_t axioms_size = 10;
    const std::string stringAxioms[axioms_size];
    std::vector<const Expression*> axioms;
    std::vector<const Expression*> expressions;
    std::map<size_t, size_t> hash_expressions;

    ExpressionUtils();
public:
    static ExpressionUtils* getInstance()
    {
        static ExpressionUtils utils;
        return &utils;
    }

    std::map<char, size_t> variables;
    int isAxiom(const Expression *expr);
    void addExpression(const Expression *expr);
    std::pair<size_t, size_t> getModusPones(const Expression *expr);

};

#endif

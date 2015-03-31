#ifndef EXPRESSION_UTILS_H_
#define EXPRESSION_UTILS_H_

#include <typeinfo>
#include <string>
#include "Expression.h"
#include <vector>
#include <map>
#include <unordered_map>
#include <memory>

struct ExpressionHash
{
    size_t operator()(const Expression* e) const
    {
        return e->getHash();
    }
};

struct ExpressionEquals
{
    bool operator()(const Expression* e1, const Expression* e2) const
    {
        return e1->isEqual(e2);
    }
};

class ExpressionUtils
{
private:
    static const size_t axioms_size = 10;
    const std::string stringAxioms[axioms_size];
    std::vector<const Expression*> axioms;
    std::vector<std::shared_ptr<const Expression>> expressions;
    std::unordered_map<const Expression*, size_t, ExpressionHash, ExpressionEquals> mymap;

    ExpressionUtils();
public:
    static ExpressionUtils* getInstance()
    {
        static ExpressionUtils utils;
        return &utils;
    }

    std::map<std::string, size_t> variables;
    int isAxiom(const Expression *expr);
    void addExpression(const Expression *expr);
    std::pair<size_t, size_t> getModusPones(const Expression *expr);

};

#endif

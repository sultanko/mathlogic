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
    const Expression* proposal;
    std::string proposalStr;
    std::vector<const Expression*> assumptions;

    ExpressionUtils();
    ~ExpressionUtils();
public:
    static ExpressionUtils* getInstance()
    {
        static ExpressionUtils utils;
        return &utils;
    }

    std::map<std::string, size_t> variables;
    int isAxiom(const Expression *expr);
    int isAssumption(const Expression *expr);
    void addExpression(const Expression *expr);
    std::pair<size_t, size_t> getModusPones(const Expression *expr);
    void addHeader(std::string str);
    void writeSelfProof();


    const std::string& getProposalString() const
    {
        return proposalStr;
    }


    Expression const *getProposal() const
    {
        return proposal;
    }


    std::vector<Expression const *> const &getExpressions() const
    {
        return expressions;
    }

private:
    template <class T>
    void safeDeleteVector(std::vector<const T*> vec)
    {
        for (auto item : vec)
        {
            delete item;
        }
        vec.clear();
    }

};

#endif

#ifndef PROOF_CHECK_H
#define PROOF_CHECK_H

#include <string>
#include <unordered_map>
#include <functional>
#include <vector>
#include <map>
#include "../Parser/Expression.h"
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

class ProofCheck
{
public:
    ProofCheck();

    int isAxiom(const Expression *expr);
    void addExpression(const Expression *expr);
    void addExpression(std::shared_ptr<const Expression> expr);
    bool wasExpression(std::shared_ptr<const Expression> expr);
    std::pair<size_t, size_t> getModusPones(const Expression *expr);

    void clearData();

    static ProofCheck* getInstance()
    {
        static ProofCheck utils;
        return &utils;
    }

    std::shared_ptr<const Expression>& getExpression(size_t i);

private:
    static const size_t axioms_size = 10;
    const std::string stringAxioms[axioms_size];
    std::vector<std::shared_ptr<const Expression> > axioms;
    std::vector<std::shared_ptr<const Expression> > expressions;
    std::unordered_map<const Expression*, size_t, ExpressionHash, ExpressionEquals> hashmap;

    static std::map<std::string, size_t> variables;
    friend class Variable;
};
#endif

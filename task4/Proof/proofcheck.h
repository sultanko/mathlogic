#ifndef PROOF_CHECK_H
#define PROOF_CHECK_H

#include <string>
#include <functional>
#include <vector>
#include <map>
#include "../Parser/Expression.h"
#include <unordered_map>

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

struct PredicatResult
{
    const Expression* notFreeTerm;
    const Expression* formula;
    std::string varName;
    bool error;
    int num;

};

class ProofCheck
{
public:
    ProofCheck();

    int isAxiom(const Expression *expr);
    int isArithmAxiom(const Expression *expr);
    void addExpression(const Expression *expr);
    void addExpression(std::shared_ptr<const Expression> expr);
    int wasExpression(std::shared_ptr<const Expression> expr);
    std::pair<size_t, size_t> getModusPones(const Expression *expr);
    PredicatResult getPredicatRule(const Expression *expr);
    PredicatResult isPredicatAxiom(const Expression *expr);

    void clearData();

    static ProofCheck* getInstance()
    {
        static ProofCheck utils;
        return &utils;
    }

    std::shared_ptr<const Expression>& getExpression(size_t i);

private:
    static const size_t axioms_size = 10;
    static const std::string stringAxioms[axioms_size];
    static const size_t arithm_axioms_size = 8;
    static const std::string stringArithmAxioms[arithm_axioms_size];
    std::vector<std::shared_ptr<const Expression> > axioms;
    std::vector<std::shared_ptr<const Expression> > arithm_axioms;
    std::vector<std::shared_ptr<const Expression> > expressions;
    std::unordered_map<const Expression*, size_t, ExpressionHash, ExpressionEquals> hash_map;

    static std::map<std::string, const Expression*> variables;
    friend class Variable;
    friend class Predicat;
};
#endif

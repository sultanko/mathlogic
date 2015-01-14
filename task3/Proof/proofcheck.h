#ifndef PROOF_CHECK_H
#define PROOF_CHECK_H

#include <string>
#include <functional>
#include <vector>
#include <map>
#include "../Parser/Expression.h"

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
    std::map<size_t, std::vector<size_t> > hash_expressions;

    static std::map<std::string, size_t> variables;
    friend class Variable;
};
#endif

#ifndef PROOF_DEDUCTION_H
#define PROOF_DEDUCTION_H

#include <vector>
#include <string>
#include "../Parser/Expression.h"
#include "proofcheck.h"

class ProofDeduction
{
private:
    std::shared_ptr<const Expression> proposal;
    std::vector<std::string> proposalFreeVariables;
    std::string proposalStr;
    std::vector<std::shared_ptr<const Expression> > assumptions;
    ProofCheck proofCheck;
    std::string errstr;

public:
    int isAssumption(const Expression *expr);
    void addHeader(std::string str);
    bool writeProof(const std::string& str, std::vector<std::shared_ptr<const Expression>>& vout);
    void writeProof(std::shared_ptr<Expression const> now, std::vector<std::shared_ptr<Expression const>> &vout);
    void writeSelfProof(std::vector<std::shared_ptr<Expression const>>& vout);
    void writeAxiomProof(std::shared_ptr<Expression const> now, std::vector<std::shared_ptr<Expression const>> &vout);
    void writeMpProof(std::shared_ptr<Expression const> now, std::vector<std::shared_ptr<Expression const>> &vout);
    void writeRuleExistProof(std::shared_ptr<Expression const> now, std::vector<std::shared_ptr<Expression const>> &vout);
    void writeRuleAllProof(std::shared_ptr<Expression const> now, std::vector<std::shared_ptr<Expression const>> &vout);

    void clearData();

    static ProofDeduction* getInstance()
    {
        static ProofDeduction proofDeduction;
        return &proofDeduction;
    }


    std::shared_ptr<Expression const> const &getProposal() const
    {
        return proposal;
    }

    void setProposal(std::shared_ptr<Expression const> const &proposal)
    {
        ProofDeduction::proposal = proposal;
        proposalStr = "(" + proposal->toString() + ")";
    }

    void addAssumption(const Expression* expr)
    {
        assumptions.emplace_back(expr);
    }


    std::string &getErrstr()
    {
        return errstr;
    }
};
#endif

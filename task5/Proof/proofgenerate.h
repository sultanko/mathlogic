#ifndef PROOF_GENERATE_H
#define PROOF_GENERATE_H

#include <string>
#include <vector>
#include <map>
#include "../Parser/Expression.h"
#include "proofdeduction.h"

class ProofGenerate
{
public:

    void proofThis(std::string str);


    static ProofGenerate* getInstanse()
    {
        static ProofGenerate proofGenerate;
        return &proofGenerate;
    }

private:
    std::shared_ptr<const Expression> statement;
    std::map<std::string, bool> varValues;
    ProofDeduction proofDeduction;

    typedef std::pair< std::map<std::string, bool>, std::vector<std::shared_ptr<const Expression>>> proofItem;
    std::vector<proofItem> blocks;
    static std::string excludeThird[];

    void variableProof(std::string varName, ProofGenerate::proofItem &vin);
    bool checkTavtologi(std::map<std::string, bool>::iterator it);
    void writeProofParts(std::map<std::string, bool>::iterator it);
    void writeProof();

    typedef std::vector<proofItem>::iterator blockIter;
    ProofGenerate::blockIter findNegate(ProofGenerate::blockIter itBlock, std::string varName);
    void writeExcludeThird(std::vector<std::shared_ptr<Expression const>> &vout, std::string varName);

};

#endif

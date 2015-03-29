#ifndef KVANTOR_ALL_H_
#define KVANTOR_ALL_H_

#include "kvantor.h"

class KvantorExist : public Kvantor
{
public:
    template <typename T1, typename T2>
    KvantorExist(T1 var, T2 term) : Kvantor(var, term, "?")
    {
        hash_string = std::hash<std::string>()(toString());
    }
    bool calculate(const std::map<std::string, bool>& variables) const;

    virtual std::shared_ptr<const Expression> substitute(std::map<std::string, std::shared_ptr<Expression const> > &comparasion) const override;
};
#endif

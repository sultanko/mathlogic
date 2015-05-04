//
// Created by sultan on 30.04.15.
//

#ifndef TASK4_PAIRKRIPKE_H
#define TASK4_PAIRKRIPKE_H


#include "../Parser/Expression.h"
#include <set>
#include <memory>
#include <vector>

class PairKripke
{
private:
    struct Part
    {
        struct ptr_compare
        {
            bool operator()(const std::shared_ptr<const Expression>& p1,
                            const std::shared_ptr<const Expression>& p2)
            {
                return p1.get() < p2.get();
            }
        };
        std::set<std::shared_ptr<const Expression>, ptr_compare> formuls;
    };

    Part truth;
    Part lie;

public:
    class Result;

    void addFalse(const Expression* expr);

    class Result
    {
        std::vector<std::shared_ptr<PairKripke>> models;
        bool succes;

    public:
        void addModel(std::shared_ptr<PairKripke> model)
        {
            models.push_back(model);
        }

        std::vector<std::shared_ptr<PairKripke>> const &getModels() const
        {
            return models;
        }

        void setSucces(bool succes)
        {
            Result::succes = succes;
        }

        bool isSucces() const
        {
            return succes;
        }
    };
};


#endif //TASK4_PAIRKRIPKE_H

//
// Created by sultan on 07.05.15.
//

#ifndef TASK8_CNF_H
#define TASK8_CNF_H

#include <memory>
#include <iostream>
#include "Expression.h"
#include <boost/multiprecision/gmp.hpp>

class Atom;
class Form;

class CNF
{
    template <typename T>
    using sptr = std::shared_ptr<T>;
public:
    typedef sptr<const CNF> cptr;
public:
    virtual cptr rst() const = 0;
    virtual boost::multiprecision::mpz_int fco() const = 0;
    virtual cptr fe() const = 0;
    virtual cptr limitPart() const;
    virtual boost::multiprecision::mpz_int natPart() const;
    virtual bool finp() const = 0;
    size_t length() const;
    size_t size() const;
    int compare(const cptr& oth) const;
    bool isZero() const;
    virtual bool limitp() const;
    friend size_t c1(const cptr& a, const cptr& b);
    friend size_t c2(const cptr& a, const cptr& b, size_t n);
    friend cptr restn(const cptr& a, size_t n);
    friend cptr padd(const cptr& a, const cptr& b, size_t n);
    friend cptr pmult(const cptr& a, const cptr& b, size_t n);
    friend cptr fastMul(const cptr& a, const cptr& b);

    friend boost::multiprecision::mpz_int expw(
            const boost::multiprecision::mpz_int& k, const cptr& a);
    friend cptr exp1(const boost::multiprecision::mpz_int& k, const cptr& a);
    friend cptr exp2(const cptr& a, const boost::multiprecision::mpz_int& k);
    friend cptr exp3h(
            const cptr& a,
            const boost::multiprecision::mpz_int& p,
            size_t n,
            const boost::multiprecision::mpz_int& k);
    friend cptr exp3(const cptr& a, const boost::multiprecision::mpz_int& k);
    friend cptr exp4(const cptr& a, const cptr& b);

    friend bool operator<(const cptr& a, const cptr& b);
    friend bool operator==(const cptr& a, const cptr& b);
    friend cptr operator+(const cptr& a, const cptr& b);
    friend cptr operator-(const cptr& a, const cptr& b);
    friend cptr operator*(const cptr& a, const cptr& b);
    friend cptr operator^(const cptr& a, const cptr& b);

    static cptr exprToCNF(const sptr<const Expression>& expr);

    friend std::ostream& operator<<(std::ostream& os, const cptr& a);
};

class Atom : public CNF
{
    boost::multiprecision::mpz_int value;
public:
    Atom(const std::string& str) : value(str) {}
    Atom(const boost::multiprecision::mpz_int& val) : value(val) {}
    virtual cptr rst() const override;

    virtual boost::multiprecision::mpz_int fco() const override;

    virtual cptr fe() const override;

    virtual bool finp() const override;

    static cptr createAtom(const boost::multiprecision::mpz_int& value);
};

class Form : public CNF
{
    cptr a;
    boost::multiprecision::mpz_int b;
    cptr c;
public:
    Form(const cptr& a, const boost::multiprecision::mpz_int& b, const cptr& c) : a(a), b(b), c(c) {}

    virtual cptr rst() const override;

    virtual boost::multiprecision::mpz_int fco() const override;

    virtual cptr fe() const override;

    virtual bool finp() const override;

    static cptr createForm(const cptr& a, const boost::multiprecision::mpz_int& b, const cptr& c);
    static cptr createW();
};


#endif //TASK8_CNF_H

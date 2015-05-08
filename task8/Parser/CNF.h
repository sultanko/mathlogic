//
// Created by sultan on 07.05.15.
//

#ifndef TASK8_CNF_H
#define TASK8_CNF_H

#include <memory>
#include <iostream>
#include "Expression.h"

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
    virtual long long fco() const = 0;
    virtual cptr fe() const = 0;
    virtual cptr limitPart() const;
    virtual long long natPart() const;
    virtual bool finp() const = 0;
    size_t length() const;
    size_t size() const;
    int compare(const cptr& oth) const;
    bool isZero() const;
    virtual bool limitp() const = 0;
    friend size_t c1(const cptr& a, const cptr& b);
    friend size_t c2(const cptr& a, const cptr& b, size_t n);
    friend cptr restn(const cptr& a, size_t n);
    friend cptr padd(const cptr& a, const cptr& b, size_t n);
    friend cptr pmult(const cptr& a, const cptr& b, size_t n);
    friend cptr fastMul(const cptr& a, const cptr& b);

    friend long long expw(long long k, const cptr& a);
    friend cptr exp1(long long k, const cptr& a);
    friend cptr exp2(const cptr& a, long long k);
    friend cptr exp3h(const cptr& a, long long p, long long n, long long k);
    friend cptr exp3(const cptr& a, long long k);
    friend cptr exp4(const cptr& a, const cptr& b);

    friend bool operator<(const cptr& a, const cptr& b);
    friend bool operator==(const cptr& a, const cptr& b);
    friend cptr operator+(const cptr& a, const cptr& b);
    friend cptr operator-(const cptr& a, const cptr& b);
    friend cptr operator*(const cptr& a, const cptr& b);
    friend cptr operator^(const cptr& a, const cptr& b);

    static cptr exprToCNF(const sptr<const Expression>& expr);
};

class Atom : public CNF
{
    long long value;
public:
    Atom(long long value) : value(value) {}
    virtual cptr rst() const override;

    virtual long long fco() const override;

    virtual cptr fe() const override;

    virtual bool finp() const override;

    virtual bool limitp() const override;

    static cptr createAtom(long long value);
};

class Form : public CNF
{
    cptr a;
    long long b;
    cptr c;
public:
    Form(const cptr& a, long long b, const cptr& c) : a(a), b(b), c(c) {}

    virtual cptr rst() const override;

    virtual long long fco() const override;

    virtual cptr fe() const override;

    virtual bool finp() const override;

    virtual bool limitp() const override;

    static cptr createForm(const cptr& a, long long b, const cptr& c);
    static cptr createW();
};


#endif //TASK8_CNF_H

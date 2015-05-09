//
// Created by sultan on 07.05.15.
//

#include "CNF.h"
#include <exception>
#include <cmath>

using namespace std;
using namespace boost::multiprecision;

CNF::cptr Atom::rst() const
{
    throw new std::runtime_error("rst atom");
}

boost::multiprecision::mpz_int Atom::fco() const
{
    return value;
}

bool Atom::finp() const
{
    return true;
}

CNF::cptr Atom::fe() const
{
    return Atom::createAtom(0);
}

CNF::cptr Form::rst() const
{
    return c;
}

boost::multiprecision::mpz_int Form::fco() const
{
    return b;
}

CNF::cptr Form::fe() const
{
    return a;
}

bool Form::finp() const
{
    return (fco() == 0);
}

size_t CNF::length() const
{
    return (finp() ? 0 : (1 + rst()->length()));
}

size_t CNF::size() const
{
    return (finp() ? 1 : (fe()->size() + rst()->size()));
}

int CNF::compare(const CNF::cptr& oth) const
{
    if (finp() && oth->finp())
    {
//        return naturalCompare(fco(), oth->fco());
        return fco().compare(oth->fco());
    }
    if (finp())
    {
        return -1;
    }
    if (oth->finp())
    {
        return 1;
    }
    int c1 = fe()->compare(oth->fe());
    if (c1 != 0) {
        return c1;
    }
    int c2 = fco().compare(oth->fco());
    if (c2 != 0) {
        return c2;
    }
    return rst()->compare(oth->rst());
}

bool operator<(const CNF::cptr& th, const CNF::cptr& oth)
{
    return th->compare(oth) == -1;
}

bool operator==(const CNF::cptr& th, const CNF::cptr& oth)
{
    return th->compare(oth) == 0;
}

CNF::cptr operator+(const CNF::cptr& a, const CNF::cptr& b)
{
    if (a->finp() && b->finp()) {
        return Atom::createAtom(a->fco() + b->fco());
    }
    if (a->fe()->compare(b->fe()) == -1) {
        return b;
    }
    if (a->fe()->compare(b->fe()) == 0) {
        return Form::createForm(a->fe(), a->fco() + b->fco(), b->rst());
    }
    return Form::createForm(a->fe(), a->fco(), a->rst() + b);
}

CNF::cptr operator-(const CNF::cptr& a, const CNF::cptr& b)
{
    if (a->finp() && b->finp()) {
        if (a->fco().compare(b->fco()) <= 0) {
            return Atom::createAtom(0);
        } else {
            return Atom::createAtom(a->fco() - b->fco());
        }
    }
    if (a->fe() < b->fe()) {
        return Atom::createAtom(0);
    }
    if (a->fe() > b->fe()) {
        return a;
    }
    if (a->fco().compare(b->fco()) == -1) {
        return Atom::createAtom(0);
    }
    if (a->fco().compare(b->fco()) == 1) {
        return Form::createForm(a->fe(), a->fco() - b->fco(), a->rst());
    }
    return a->rst() - b->rst();
}

CNF::cptr operator*(const CNF::cptr& a, const CNF::cptr& b)
{
    if (a->isZero() || b->isZero()) {
        return Atom::createAtom(0);
    }
    if (a->finp() && b->finp()) {
        return Atom::createAtom(a->fco() * b->fco());
    }
    if (b->finp()) {
        return Form::createForm(a->fe(), a->fco() * b->fco(), a->rst());
    }
    return Form::createForm(a->fe() + b->fe(), b->fco(), a * b->rst());
}

bool CNF::isZero() const
{
//    return finp() && fco() == 0;
    return natPart() == 0 && fco() == 0;
}

CNF::cptr CNF::exprToCNF(const sptr<const Expression>& expr)
{
    const std::string op = expr->getOperator();
    if (op == "+") {
        return (exprToCNF(expr->getLeft()) + exprToCNF(expr->getRight()));
    } else if (op == "-") {
        return (exprToCNF(expr->getLeft()) - exprToCNF(expr->getRight()));
    } else if (op == "*") {
        return (exprToCNF(expr->getLeft()) * exprToCNF(expr->getRight()));
    } else if (op == "^") {
        return (exprToCNF(expr->getLeft()) ^ exprToCNF(expr->getRight()));
    } else if (op == "w") {
        return (Form::createW());
    } else {
        return CNF::cptr(new Atom(op));
//        try
//        {
//            return Atom::createAtom(std::stoll(op));
//        } catch (std::invalid_argument e) {
//            std::cerr << expr->getOperator() << "\n";
//            std::cerr << e.what() << "\n";
//            throw e;
//        }
    }
}

bool CNF::limitp() const
{
    return (finp() ? fco() == 0 : rst()->limitp());
}

CNF::cptr restn(CNF::cptr const &a, size_t n)
{
    return (n == 0 ? a : restn(a->rst(), n - 1));
}

size_t c1(CNF::cptr const &a, CNF::cptr const &b)
{
    if (a->fe()->compare(b->fe()) == 1) {
        return 1 + c1(a->rst(), b);
    } else {
        return 0;
    }
}

size_t c2(const CNF::cptr& a, CNF::cptr const &b, size_t n)
{
    return n + c1(restn(a, n), b);
}

CNF::cptr padd(CNF::cptr const &a, CNF::cptr const &b, size_t n)
{
    if (n == 0) {
        return a + b;
    } else {
        return Form::createForm(a->fe(), a->fco(), padd(a->rst(), b, n - 1));
    }
}

CNF::cptr pmult(CNF::cptr const &a, CNF::cptr const &b, size_t n)
{
    if (a->isZero() || b->isZero()) {
        return Atom::createAtom(0);
    }
    if (a->finp() && b->finp()) {
        return Atom::createAtom(a->fco() * b->fco());
    }
    if (b->finp()) {
        return Form::createForm(a->fe(), a->fco() * b->fco(), a->rst());
    }
    const size_t m = c2(a->fe(), b->fe(), n);
    return Form::createForm(padd(a->fe(), b->fe(), m),
                            b->fco(),
                            pmult(a, b->rst(), m));
}

CNF::cptr Atom::createAtom(const boost::multiprecision::mpz_int& value)
{
    static cptr zero(new Atom("0"));
    static cptr one(new Atom("1"));
    if (value.is_zero()) {
        return zero;
    }
    if (value == 1) {
        return one;
    }
    return std::shared_ptr<CNF const>(new Atom(value));
}

CNF::cptr Form::createForm(CNF::cptr const &a, const boost::multiprecision::mpz_int& b, CNF::cptr const &c)
{
    return std::shared_ptr<CNF const>(new Form(a, b, c));
}

CNF::cptr fastMul(CNF::cptr const &a, CNF::cptr const &b)
{
    return pmult(a, b, 0);
}

CNF::cptr exp1(const boost::multiprecision::mpz_int& k, const CNF::cptr& a)
{
    using namespace boost::multiprecision;
    if (k == 0) {
        return Atom::createAtom(0);
    }
    if (a == Atom::createAtom(1)) {
        return Form::createForm(Atom::createAtom(a->fco()),
                                expw(k, a->rst()),
                                Atom::createAtom(0));
    }
    if (a->rst()->finp()) {
        return Form::createForm(
                Form::createForm(a->fe() - Atom::createAtom(1), a->fco(), Atom::createAtom(0)),
                expw(k, a->rst()),
                Atom::createAtom(0)
        );
    }
    auto c = exp1(k, a->rst());
    return Form::createForm(Form::createForm(a->fe() - Atom::createAtom(1), 1, c->fe()),
                            c->fco(),
                            Atom::createAtom(0));
}

boost::multiprecision::mpz_int expw(const boost::multiprecision::mpz_int& k, CNF::cptr const &a)
{
//    std::cerr << "Expw: " << k << " " << a->fco() << " " << (k^a->fco()) << "\n";
    return pow(k, a->fco().convert_to<size_t>());
}

CNF::cptr Form::createW()
{
    return Form::createForm(
            Form::createForm(Atom::createAtom(0), 1, Atom::createAtom(0)),
            1,
            Atom::createAtom(0)
    );
}

boost::multiprecision::mpz_int CNF::natPart() const
{
    return (finp() ? fco() : rst()->natPart());
}

CNF::cptr CNF::limitPart() const
{
    return (finp() ? Atom::createAtom(0) : Form::createForm(fe(), fco(), rst()->limitPart()));
}

CNF::cptr exp2(CNF::cptr const &a, const boost::multiprecision::mpz_int& k)
{
    if (k == 0) {
        return Atom::createAtom(1);
    }
    return
            fastMul(
                    Form::createForm(fastMul(a->fe(), Atom::createAtom(k - 1)), 1, Atom::createAtom(0)),
                    a);
}

CNF::cptr exp3h(CNF::cptr const &a, const mpz_int& p, size_t n, const mpz_int& k)
{
    if (k == 1) {
        return fastMul(a, Atom::createAtom(p)) + Atom::createAtom(p);
    }
    return padd(fastMul(exp2(a, k), Atom::createAtom(p)), exp3h(a, p, n, k-1), n);
}


CNF::cptr exp3(CNF::cptr const &a, const mpz_int& k)
{
    if (k == 0) {
        return Atom::createAtom(1);
    }
    if (k == 1) {
        return a;
    }
    if (a->limitp()) {
        return exp2(a, k);
    }
    auto c = a->limitPart();
    size_t n = a->length();
    return padd(exp2(c, k),
                exp3h(c, a->natPart(), n, k-1),
                n);
}

CNF::cptr exp4(CNF::cptr const &a, CNF::cptr const &b)
{
    return fastMul(
            Form::createForm(fastMul(a->fe(), b->limitPart()), 1, Atom::createAtom(0)),
            exp3(a, b->natPart())
    );
}

CNF::cptr operator^(CNF::cptr const &a, CNF::cptr const &b)
{
    if (b->isZero() || (a == Atom::createAtom(1))) {
        return Atom::createAtom(1);
    }
    if (a->isZero()) {
        return Atom::createAtom(0);
    }
    if (a->finp() && b->finp()) {
        return Atom::createAtom(expw(a->fco(), b));
    }
    if (a->finp()) {
        return exp1(a->fco(), b);
    }
    if (b->finp()) {
        return exp3(a, b->fco());
    }
    return exp4(a, b);
}

std::ostream& operator<<(std::ostream& os, const CNF::cptr& a)
{
    if (a->finp())
    {
        return os << a->fco();
    }
    if (a->fe()->isZero())
    {
        os << a->fco();
    }
    else
    {
        os << "w" << "^" << "(" << a->fe() << ")";
        if (a->fco() != 1)
        {
            os << "*" << a->fco();
        }
        if (!a->rst()->isZero())
        {
            os << "+" << a->rst();
        }
    }
    return os;
}

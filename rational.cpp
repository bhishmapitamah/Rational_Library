#include "rational.h"

// Parameterized Constructor
rational::rational(Type num, Type den) {
    if(den < 0)den = -den, num = -num;
    _den = den;
    _num = num;
}

// Find GCD of Two numbers
Type rational::GCD(Type a, Type b) {
    Type c;
    if(a > b) {
        c = a;
        a = b;
        b = c;
    }
    while(a) {
        c = a;
        a = b % a;
        b = c;
    }
    return b;
}

// Simplify the rational number
void rational::simplify() {
    Type gcd=GCD(_num,_den);
    _num/=gcd;
    _den/=gcd;
}

// += Operator Overloading
rational& rational::operator+=(const rational& rhs) {
    _num = _num * rhs._den + rhs._num * _den;
    _den = _den * rhs._den;
    return *this;
}
rational& rational::operator+=(const Type& rhs) {
    _num += _den * rhs;
    return *this;
}

// -= Operator Overloading
rational& rational::operator-=(const rational& rhs) {
    _num = _num * rhs._den - rhs._num * _den;
    _den = _den * rhs._den;
    return *this;
}
rational& rational::operator-=(const Type& rhs) {
    _num -= _den * rhs;
    return *this;
}

// *= Operator Overloading
rational& rational::operator*=(const rational& rhs) {
    _num = _num * rhs._num;
    _den = _den * rhs._den;
    return *this;
}
rational& rational::operator*=(const Type& rhs) {
    _num *= rhs;
    return *this;
}

// /=Operator Overloading
rational& rational::operator/=(const rational& rhs) {
    _num = _num * rhs._den;
    _den = _den * rhs._num;
    if(_den < 0)_den = -_den, _num = -_num;
    return *this;
}
rational& rational::operator/=(const Type& rhs) {
    _den *= rhs;
    if(_den < 0)_den = -_den, _num = -_num;
    return *this;
}

// Unary + Operator Overloading
rational& rational::operator+() {
    return *this;
}

// Unary - Operator Overloading
rational rational::operator-() {
    rational temp(*this);
    temp._num = - temp._num;
    return temp;
}

// Increment Operator Overloading
rational& rational::operator++() {
    *this += 1;
    return *this;
}
rational rational::operator++(int) {
    rational temp(*this);
    ++*this;
    return temp;
}

// Decrement Operator Overloading
rational& rational::operator--() {
    *this -= 1;
    return *this;
}
rational rational::operator--(int) {
    rational temp(*this);
    --*this;
    return temp;
}

// Overloading for output stream
std::ostream& operator<<(std::ostream& out, const rational& print) {
    out << print._num;
    if(print._den > 1)out << "/" << print._den;
    return out;
}

// Overloading for input stream
std::istream& operator>>(std::istream& in, rational& input) {
    in >> input._num >> input._den;
    return in;
}

// + Operator Overloading
inline rational operator+(rational lhs, const rational& rhs) {
    lhs += rhs;
    return lhs;
}
inline rational operator+(rational lhs, const Type& rhs) {
    lhs += rhs;
    return lhs;
}
inline rational operator+(const Type& lhs, rational rhs) {
    rhs += lhs;
    return rhs;
}

// - Operator Overloading
inline rational operator-(rational lhs, const rational& rhs) {
    lhs -= rhs;
    return lhs;
}
inline rational operator-(rational lhs, const Type& rhs) {
    lhs += rhs;
    return lhs;
}
inline rational operator-(const Type& lhs, rational rhs) {
    rhs += lhs;
    return rhs;
}

// * Operator Overloading
inline rational operator*(rational lhs, const rational& rhs) {
    lhs *= rhs;
    return lhs;
}
inline rational operator*(rational lhs, const Type& rhs) {
    lhs += rhs;
    return lhs;
}
inline rational operator*(const Type& lhs, rational rhs) {
    rhs += lhs;
    return rhs;
}

// / Operator Overloading
inline rational operator/(rational lhs, const rational& rhs) {
    lhs /= rhs;
    return lhs;
}
inline rational operator/(rational lhs, const Type& rhs) {
    lhs += rhs;
    return lhs;
}
inline rational operator/(const Type& lhs, rational rhs) {
    rhs += lhs;
    return rhs;
}

// < Operator Overloading
inline bool operator<(const rational& lhs, const rational& rhs) {
    return (lhs.num() * rhs.den() < rhs.num() * lhs.den());
}
inline bool operator<(const rational& lhs, const Type& rhs) {
    return (lhs.num() < rhs * lhs.den());
}
inline bool operator<(const Type& lhs, const rational& rhs) {
    return (lhs * rhs.den() < rhs.num());
}

// > Operator Overloading
inline bool operator>(const rational& lhs, const rational& rhs) {
    return (rhs < lhs);
}
inline bool operator>(const rational& lhs, const Type& rhs) {
    return (rhs < lhs);
}
inline bool operator>(const Type& lhs, const rational& rhs) {
    return (rhs < lhs);
}

// <= Operator Overloading
inline bool operator<=(const rational& lhs, const rational& rhs) {
    return !(lhs > rhs);
}
inline bool operator<=(const rational& lhs, const Type& rhs) {
    return !(lhs > rhs);
}
inline bool operator<=(const Type& lhs, const rational& rhs) {
    return !(lhs > rhs);
}

// >= Operator Overloading
inline bool operator>=(const rational& lhs, const rational& rhs) {
    return !(lhs < rhs);
}
inline bool operator>=(const rational& lhs, const Type& rhs) {
    return !(lhs < rhs);
}
inline bool operator>=(const Type& lhs, const rational& rhs) {
    return !(lhs < rhs);
}

// == Operator Overloading
inline bool operator==(const rational& lhs, const rational& rhs) {
    return (float(lhs / rhs) == 1);
}
inline bool operator==(const rational& lhs, const Type& rhs) {
    return (float(lhs / rhs) == 1);
}
inline bool operator==(const Type& lhs, const rational& rhs) {
    return (float(lhs / rhs) == 1);
}

// != Operator Overloading
inline bool operator!=(const rational& lhs, const rational& rhs) {
    return !(lhs == rhs);
}
inline bool operator!=(const rational& lhs, const Type& rhs) {
    return !(lhs == rhs);
}
inline bool operator!=(const Type& lhs, const rational& rhs) {
    return !(lhs == rhs);
}

// Absolute value of the rational variable
inline rational abs(rational& num) {
    return (num.num() < 1 ? -num : num);
}

int main(){
    rational obj(56,1),obj2(45,154);
    rational obj3 = obj2 / 5;
    //obj3/=obj2;
    obj /= 2;
    std::cout<<obj<<std::endl<<obj3;
    std::cout<<std::endl<<(3 > obj);
    //std::cout<<obj3<<obj<<obj2;
    return 0;
}
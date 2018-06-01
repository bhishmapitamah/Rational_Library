#include "rational.h"

// Default Constructor
rational::rational():_num(1),_den(1) {}

// Parameterized Constructor
rational::rational(Type num,Type den):_num(num),_den(den) {}

// Find GCD of Two numbers
Type rational::GCD(Type a, Type b) {
    Type c;
    if(a>b) {
        c = a;
        a = b;
        b = c;
    }
    while(a) {
        c=a;
        a=b%a;
        b=c;
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
    _num=_num*rhs._den+rhs._num*_den;
    _den=_den*rhs._den;
    return *this;
}

// -= Operator Overloading
rational& rational::operator-=(const rational& rhs) {
    _num=_num*rhs._den-rhs._num*_den;
    _den=_den*rhs._den;
    return *this;
}

// *= Operator Overloading
rational& rational::operator*=(const rational& rhs) {
    _num=_num*rhs._num;
    _den=_den*rhs._den;
    return *this;
}

// /=Operator Overloading
rational& rational::operator/=(const rational& rhs) {
    _num=_num*rhs._den;
    _den=_den*rhs._num;
    return *this;
}

// Unary + Operator Overloading
rational& rational::operator+() {
    return *this;
}

// Unary - Operator Overloading
rational rational::operator-() {
    rational temp(*this);
    temp._num=-temp._num;
    return temp;
}

// Function to change denominator
Type rational::den(Type d) {
    _den=d;
    return _den;
}

// Function to change numerator
Type rational::num(Type n) {
    _num=n;
    return _num;
}

// Overloading for output stream
std::ostream& operator<<(std::ostream& out, const rational& print) {
    out<<print._num;
    if(print._den > 1)out<<" / "<<print._den;
    return out;
}

// Overloading for input stream
std::istream& operator>>(std::istream& in, rational& input) {
    in>>input._num>>input._den;
    return in;
}

// + Operator Overloading
inline rational operator+(rational lhs, const rational& rhs) {
    lhs+=rhs;
    return lhs;
}

// - Operator Overloading
inline rational operator-(rational lhs, const rational& rhs) {
    lhs-=rhs;
    return lhs;
}

// * Operator Overloading
inline rational operator*(rational lhs, const rational& rhs) {
    lhs*=rhs;
    return lhs;
}

// / Operator Overloading
inline rational operator/(rational lhs, const rational& rhs) {
    lhs/=rhs;
    return lhs;
}

// < Operator Overloading
inline bool operator<(const rational& lhs, const rational& rhs) {
    return (lhs.num()*rhs.den()<rhs.num()*lhs.den());
}

// > Operator Overloading
inline bool operator>(const rational& lhs, const rational& rhs) {
    return (rhs<lhs);
}

// <= Operator Overloading
inline bool operator<=(const rational& lhs, const rational& rhs) {
    return !(lhs>rhs);
}

// >= Operator Overloading
inline bool operator>=(const rational& lhs, const rational& rhs) {
    return !(lhs<rhs);
}

// == Operator Overloading
inline bool operator==(const rational& lhs, const rational& rhs) {
    return (lhs.num()==rhs.num())&&(rhs.den()==lhs.den());
}

// != Operator Overloading
inline bool operator!=(const rational& lhs, const rational& rhs) {
    return !(lhs==rhs);
}

int main(){
    rational obj(56,77),obj2(45,154);
    rational obj3;
    //obj3/=obj2;
    std::cout<<obj2;
    obj3.simplify();
    //std::cout<<obj3<<obj<<obj2;
    return 0;
}
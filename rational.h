#ifndef _cpp_rational
#define _cpp_rational
#include <cstdint>
#include <iostream>

typedef intmax_t Type;

class rational{
    Type _num;
    Type _den;
public:
    rational() : _num(0), _den(1) {}
    explicit rational(Type, Type = 1);

    Type GCD(Type,Type);
    void simplify();

    rational& operator+=(const rational&);
    rational& operator-=(const rational&);
    rational& operator*=(const rational&);
    rational& operator/=(const rational&);

    rational& operator+=(const Type&);
    rational& operator-=(const Type&);
    rational& operator*=(const Type&);
    rational& operator/=(const Type&);

    rational& operator+();
    rational operator-();
    rational& operator++();
    rational operator++(int);
    rational& operator--();
    rational operator--(int);


    friend std::ostream& operator<<(std::ostream&,const rational&);
    friend std::istream& operator>>(std::istream&,rational&);

    explicit operator const int() const {return (int)(_num/_den);}
    explicit operator const long() const {return (long)(_num/_den);}
    explicit operator const long long() const {return ((long long)_num/_den);}
    explicit operator const float() const {return ((float)_num/_den);}
    explicit operator const double() const {return ((double)_num/_den);}
    explicit operator const bool() const {return _num != 0;}

    const Type den()const{return _den;}
    const Type num()const{return _num;}
    void set(const Type&, const Type&);

};

inline rational operator+(rational, const rational&);
inline rational operator-(rational, const rational&);
inline rational operator*(rational, const rational&);
inline rational operator/(rational, const rational&);

inline rational operator+(rational, const Type&);
inline rational operator-(rational, const Type&);
inline rational operator*(rational, const Type&);
inline rational operator/(rational, const Type&);

inline rational operator+(const Type&, rational);
inline rational operator-(const Type&, rational);
inline rational operator*(const Type&, rational);
inline rational operator/(const Type&, rational);

inline bool operator<(const rational&, const rational&);
inline bool operator>(const rational&, const rational&);
inline bool operator<=(const rational&, const rational&);
inline bool operator>=(const rational&, const rational&);
inline bool operator==(const rational&, const rational&);
inline bool operator!=(const rational&, const rational&);

inline bool operator<(const rational&, const Type&);
inline bool operator>(const rational&, const Type&);
inline bool operator<=(const rational&, const Type&);
inline bool operator>=(const rational&, const Type&);
inline bool operator==(const rational&, const Type&);
inline bool operator!=(const rational&, const Type&);

inline bool operator<(const Type&, const rational&);
inline bool operator>(const Type&, const rational&);
inline bool operator<=(const Type&, const rational&);
inline bool operator>=(const Type&, const rational&);
inline bool operator==(const Type&, const rational&);
inline bool operator!=(const Type&, const rational&);

inline rational abs(rational&);

#endif
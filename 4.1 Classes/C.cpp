#include <numeric>

class Rational {
public:
    Rational(int numerator = 0, int denominator = 1) 
        : num(numerator), denom(denominator) {
        Normalize();
    }

    int Numerator() const { return num; }
    int Denominator() const { return denom; }

    Rational operator+(const Rational& other) const {
        return Rational(num * other.denom + other.num * denom, denom * other.denom);
    }

    Rational operator-(const Rational& other) const {
        return Rational(num * other.denom - other.num * denom, denom * other.denom);
    }

    Rational operator*(const Rational& other) const {
        return Rational(num * other.num, denom * other.denom);
    }

    Rational operator/(const Rational& other) const {
        return Rational(num * other.denom, denom * other.num);
    }

    Rational operator+() const { return *this; }
    Rational operator-() const { return Rational(-num, denom); }

    Rational& operator+=(const Rational& other) {
        *this = *this + other;
        return *this;
    }

    Rational& operator-=(const Rational& other) {
        *this = *this - other;
        return *this;
    }

    Rational& operator*=(const Rational& other) {
        *this = *this * other;
        return *this;
    }

    Rational& operator/=(const Rational& other) {
        *this = *this / other;
        return *this;
    }

    bool operator==(const Rational& other) const {
        return num == other.num && denom == other.denom;
    }

    bool operator!=(const Rational& other) const {
        return !(*this == other);
    }

    friend Rational operator+(int lhs, const Rational& rhs) {
        return Rational(lhs) + rhs;
    }

    friend Rational operator-(int lhs, const Rational& rhs) {
        return Rational(lhs) - rhs;
    }

    friend Rational operator*(int lhs, const Rational& rhs) {
        return Rational(lhs) * rhs;
    }

    friend Rational operator/(int lhs, const Rational& rhs) {
        return Rational(lhs) / rhs;
    }

private:
    int num, denom;

    void Normalize() {
        int gcd = std::gcd(num, denom);
        num /= gcd;
        denom /= gcd;
        if (denom < 0) {
            num = -num;
            denom = -denom;
        }
    }
};
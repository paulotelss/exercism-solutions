#include "complex_numbers.h"
#include <cmath>

namespace complex_numbers {

Complex::Complex(double real, double imag) : r(real), i(imag) {}

Complex Complex::conj() const {
    return Complex(r, -i);
}

double Complex::abs() const {
    return std::hypot(r, i);
}

Complex operator+(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.r + rhs.r, lhs.i + rhs.i);
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.r - rhs.r, lhs.i - rhs.i);
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
    double real_part = lhs.r * rhs.r - lhs.i * rhs.i;
    double imag_part = lhs.i * rhs.r + lhs.r * rhs.i;
    return Complex(real_part, imag_part);
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
    double denom = rhs.r * rhs.r + rhs.i * rhs.i;
    double real_part = (lhs.r * rhs.r + lhs.i * rhs.i) / denom;
    double imag_part = (lhs.i * rhs.r - lhs.r * rhs.i) / denom;
    return Complex(real_part, imag_part);
}

Complex Complex::exp() const {
    double exp_real = std::exp(r);
    return Complex(exp_real * std::cos(i), exp_real * std::sin(i));
}

} // namespace complex_numbers
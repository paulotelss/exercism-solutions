#pragma once

namespace complex_numbers {

class Complex {
public:
    // Construtor sem 'explicit' permite a conversão automática de double para Complex
    Complex(double real = 0.0, double imag = 0.0);

    double real() const { return r; }
    double imag() const { return i; }

    // Nome alterado para corresponder aos testes
    Complex conj() const;
    double abs() const;
    Complex exp() const;

    // Operadores declarados como funções não-membro amigas para simetria (ex: double + Complex)
    friend Complex operator+(const Complex& lhs, const Complex& rhs);
    friend Complex operator-(const Complex& lhs, const Complex& rhs);
    friend Complex operator*(const Complex& lhs, const Complex& rhs);
    friend Complex operator/(const Complex& lhs, const Complex& rhs);

private:
    double r;
    double i;
};

} // namespace complex_numbers
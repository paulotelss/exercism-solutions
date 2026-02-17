#if !defined(TRIANGLE_H)
#define TRIANGLE_H

namespace triangle {

    enum class flavor { equilateral, isosceles, scalene };

    // Função principal de classificação
    flavor kind(double a, double b, double c);

}  // namespace triangle

#endif
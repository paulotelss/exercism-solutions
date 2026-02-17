#include "triangle.h"
#include <algorithm>
#include <stdexcept>
#include <vector>

namespace triangle {

flavor kind(double a, double b, double c) {
    // Colocamos os lados em um vetor para ordenar e facilitar a lógica
    std::vector<double> sides = {a, b, c};
    std::sort(sides.begin(), sides.end());

    // 1. Verificação de Validade: Lados > 0 e Desigualdade Triangular
    // Como está ordenado, basta checar se o menor é > 0 e se a+b >= c
    if (sides[0] <= 0 || sides[0] + sides[1] < sides[2]) {
        throw std::domain_error("Invalid triangle sides");
    }

    // 2. Classificação usando a contagem de lados iguais
    // Com os lados ordenados, a lógica fica linear:
    if (sides[0] == sides[2]) {
        return flavor::equilateral; // Se o menor é igual ao maior, todos são iguais
    }
    
    if (sides[0] == sides[1] || sides[1] == sides[2]) {
        return flavor::isosceles; // Pelo menos dois vizinhos são iguais
    }

    return flavor::scalene; // Nenhum é igual
}

}  // namespace triangle
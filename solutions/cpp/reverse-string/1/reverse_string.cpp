#include "reverse_string.h"
#include <algorithm>

namespace reverse_string {

std::string reverse_string(const std::string& text) {
    // Abordagem "fora da curva": Construtor de iteradores reversos.
    // Isso cria a string já invertida em uma única passagem de memória,
    // permitindo que o compilador otimize o tamanho (RVO - Return Value Optimization).
    return std::string(text.rbegin(), text.rend());
}

}
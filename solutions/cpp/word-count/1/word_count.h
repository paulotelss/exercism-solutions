#pragma once

#include <string>
#include <map>

namespace word_count {
    // Retorna um mapa com a contagem de cada palavra normalizada
    std::map<std::string, int> words(std::string const& input);
}
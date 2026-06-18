#pragma once

#include <string>

namespace beer_song {

    // Retorna os versos solicitados do intervalo [start, end] (inclusive)
    std::string sing(int start, int end = 0);
    
    // Auxiliar para gerar um verso individual
    std::string verse(int number);

} // namespace beer_song
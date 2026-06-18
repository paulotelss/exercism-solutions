#include "beer_song.h"
#include <sstream>

namespace beer_song {

// Helper privado para formatar a quantidade e tratar a concordância gramatical
static std::string bottles(int number, bool capitalize = false) {
    if (number == 0) {
        return capitalize ? "No more bottles of beer" : "no more bottles of beer";
    }
    if (number == 1) {
        return "1 bottle of beer";
    }
    return std::to_string(number) + " bottles of beer";
}

std::string verse(int number) {
    std::ostringstream oss;
    
    // Primeira linha do verso
    oss << bottles(number, true) << " on the wall, " << bottles(number) << ".\n";
    
    // Segunda linha do verso depende do estado atual das garrafas
    if (number == 0) {
        oss << "Go to the store and buy some more, " << bottles(99) << " on the wall.\n";
    } else {
        std::string pronoun = (number == 1) ? "it" : "one";
        oss << "Take " << pronoun << " down and pass it around, " << bottles(number - 1) << " on the wall.\n";
    }
    
    return oss.str();
}

std::string sing(int start, int end) {
    std::ostringstream song;
    
    for (int i = start; i >= end; --i) {
        song << verse(i);
        if (i > end) {
            song << "\n"; // Os testes do Exercism geralmente exigem uma quebra de linha entre versos
        }
    }
    
    return song.str();
}

} // namespace beer_song
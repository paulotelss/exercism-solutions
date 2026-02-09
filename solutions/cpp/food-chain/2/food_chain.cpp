#include "food_chain.h"
#include <vector>
#include <sstream>

namespace food_chain {

struct Animal {
    std::string name;
    std::string reaction;
    std::string extra;
};

const std::vector<Animal> animals = {
    {"fly", "", ""},
    {"spider", "It wriggled and jiggled and tickled inside her.", " that wriggled and jiggled and tickled inside her"},
    {"bird", "How absurd to swallow a bird!", ""},
    {"cat", "Imagine that, to swallow a cat!", ""},
    {"dog", "What a hog, to swallow a dog!", ""},
    {"goat", "Just opened her throat and swallowed a goat!", ""},
    {"cow", "I don't know how she swallowed a cow!", ""},
    {"horse", "She's dead, of course!", ""}
};

std::string verse(int v) {
    std::stringstream ss;
    const Animal& a = animals[v - 1];

    ss << "I know an old lady who swallowed a " << a.name << ".\n";

    if (!a.reaction.empty()) {
        ss << a.reaction << "\n";
    }

    if (a.name == "horse") {
        return ss.str();
    }

    for (int i = v - 1; i > 0; --i) {
        ss << "She swallowed the " << animals[i].name 
           << " to catch the " << animals[i - 1].name 
           << animals[i - 1].extra << ".\n";
    }

    ss << "I don't know why she swallowed the fly. Perhaps she'll die.\n";
    return ss.str();
}

// O ERRO ESTAVA AQUI: O teste exige um \n extra entre estrofes E um no final.
std::string verses(int start, int end) {
    std::stringstream ss;
    for (int i = start; i <= end; ++i) {
        ss << verse(i) << "\n"; // Adiciona o \n para separar ou finalizar
    }
    return ss.str();
}

std::string sing() {
    return verses(1, 8);
}

}  // namespace food_chain
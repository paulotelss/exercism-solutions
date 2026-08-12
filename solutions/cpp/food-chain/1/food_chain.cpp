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
        if (v < 1 || v > 8) return "";

        std::stringstream ss;
        const Animal& a = animals[v - 1];

        // Primeira linha
        ss << "I know an old lady who swallowed a " << a.name << ".\n";

        // Reação específica (se houver e não for o cavalo)
        if (!a.reaction.empty()) {
            ss << a.reaction << "\n";
        }

        // Se for o cavalo, a música acaba aqui
        if (a.name == "horse") {
            return ss.str();
        }

        // Parte cumulativa (cadeia alimentar reversa)
        for (int i = v - 1; i > 0; --i) {
            ss << "She swallowed the " << animals[i].name
                << " to catch the " << animals[i - 1].name
                << animals[i - 1].extra << ".\n";
        }

        // Conclusão padrão
        ss << "I don't know why she swallowed the fly. Perhaps she'll die.\n";

        return ss.str();
    }

    std::string verses(int start, int end) {
        std::stringstream ss;
        for (int i = start; i <= end; ++i) {
            ss << verse(i) << (i == end ? "" : "\n");
        }
        return ss.str();
    }

    std::string sing() {
        return verses(1, 8);
    }

}  // namespace food_chain
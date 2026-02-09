#include "binary.h"

namespace binary {

    int convert(const std::string& input) {
        int value = 0;

        for (char c : input) {
            // valida: só aceita '0' ou '1'
            if (c != '0' && c != '1') {
                return 0; // inválido
            }

            value = value * 2 + (c - '0');
        }

        return value;
    }

}

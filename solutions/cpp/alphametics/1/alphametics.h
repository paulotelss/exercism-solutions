#ifndef ALPHAMETICS_H
#define ALPHAMETICS_H

#include <string>
#include <map>
#include <optional> // Necessário para std::optional

namespace alphametics {
    // A assinatura agora usa optional para indicar sucesso ou falha
    std::optional<std::map<char, int>> solve(std::string puzzle);
}

#endif
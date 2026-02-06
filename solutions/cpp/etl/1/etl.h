#pragma once

#include <map>
#include <vector>
#include <string>

namespace etl {

    // Versão mais comum: valores como strings ("A", "E", ...)
    std::map<char, int> transform(const std::map<int, std::vector<std::string>>& old);

    // (Extra) Algumas versões usam vector<char>. Mantive também pra não te travar.
    std::map<char, int> transform(const std::map<int, std::vector<char>>& old);

}

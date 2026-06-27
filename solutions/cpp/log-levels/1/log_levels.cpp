#include <string>

namespace log_line {

std::string message(const std::string& line) {
    // Encontra a posição de ": " que separa o nível da mensagem
    size_t colon_pos = line.find(": ");
    if (colon_pos == std::string::npos) {
        return "";
    }
    
    // Extrai tudo o que vem após o ": "
    std::string msg = line.substr(colon_pos + 2);
    
    // Trim: Remove possíveis espaços em branco e quebras de linha no início e fim
    size_t first = msg.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) {
        return "";
    }
    size_t last = msg.find_last_not_of(" \t\r\n");
    
    return msg.substr(first, (last - first + 1));
}

std::string log_level(const std::string& line) {
    // O nível do log está sempre entre os colchetes '[' e ']'
    size_t start = line.find('[');
    size_t end = line.find(']');
    
    if (start == std::string::npos || end == std::string::npos || end <= start) {
        return "";
    }
    
    // Retorna apenas o texto contido de forma interna
    return line.substr(start + 1, end - start - 1);
}

std::string reformat(const std::string& line) {
    // Combina o resultado dos métodos anteriores
    std::string msg = message(line);
    std::string level = log_level(line);
    
    return msg + " (" + level + ")";
}

} // namespace log_line
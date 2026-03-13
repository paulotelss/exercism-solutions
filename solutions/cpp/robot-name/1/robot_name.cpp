#include "robot_name.h"
#include <algorithm>
#include <random>
#include <stdexcept> // Necessário para std::runtime_error

namespace robot_name {

std::vector<std::string> robot::available_names;
size_t robot::next_name_index = 0;

void robot::generate_all_names() {
    if (!available_names.empty()) return;

    available_names.reserve(676000);
    for (char c1 = 'A'; c1 <= 'Z'; ++c1) {
        for (char c2 = 'A'; c2 <= 'Z'; ++c2) {
            for (int d = 0; d < 1000; ++d) {
                std::string n = "";
                n += c1;
                n += c2;
                // Formatação manual para evitar dependência de std::format ou boost
                if (d < 100) n += '0';
                if (d < 10) n += '0';
                n += std::to_string(d);
                available_names.push_back(n);
            }
        }
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(available_names.begin(), available_names.end(), g);
}

robot::robot() {
    reset();
}

std::string robot::name() const {
    return robot_name;
}

void robot::reset() {
    if (available_names.empty()) {
        generate_all_names();
    }

    if (next_name_index >= available_names.size()) {
        throw std::runtime_error("Nomes esgotados.");
    }

    // Atribui o nome e incrementa o índice global
    robot_name = available_names.at(next_name_index);
    next_name_index++;
}

} // namespace robot_name
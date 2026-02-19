#include "grade_school.h"
#include <algorithm>

namespace grade_school {

bool school::add(const std::string& name, int grade) {
    // Regra: Um aluno não pode ser adicionado mais de uma vez na escola inteira.
    for (const auto& [g, students] : database) {
        if (students.find(name) != students.end()) {
            return false; 
        }
    }

    // O std::set já lida com a ordenação alfabética e unicidade.
    return database[grade].insert(name).second;
}

std::vector<std::string> school::grade(int grade_num) const {
    auto it = database.find(grade_num);
    if (it == database.end()) {
        return {};
    }
    // Converte o set interno para um vector para o retorno.
    return std::vector<std::string>(it->second.begin(), it->second.end());
}

std::map<int, std::vector<std::string>> school::roster() const {
    std::map<int, std::vector<std::string>> sorted_roster;
    
    for (const auto& [grade_num, students] : database) {
        sorted_roster[grade_num] = std::vector<std::string>(students.begin(), students.end());
    }
    
    return sorted_roster;
}

}  // namespace grade_school
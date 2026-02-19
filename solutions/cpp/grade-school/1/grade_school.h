#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H

#include <string>
#include <vector>
#include <map>
#include <set>

namespace grade_school {

class school {
public:
    // Adiciona um estudante. Retorna false se o estudante já existir em qualquer série.
    bool add(const std::string& name, int grade);

    // Retorna os nomes dos alunos de uma série específica em ordem alfabética.
    std::vector<std::string> grade(int grade) const;

    // Retorna o roster completo: séries crescentes e nomes alfabéticos.
    std::map<int, std::vector<std::string>> roster() const;

private:
    // A chave é a série, o valor é um set (único e ordenado) de nomes.
    std::map<int, std::set<std::string>> database;
};

}  // namespace grade_school

#endif
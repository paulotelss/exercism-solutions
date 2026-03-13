#pragma once

#include <string>
#include <vector>

namespace robot_name {

class robot {
public:
    robot();
    
    std::string name() const;
    void reset();

private:
    std::string robot_name;
    
    // Gerenciador estático de nomes globais
    static void generate_all_names();
    static std::vector<std::string> available_names;
    static size_t next_name_index;
};

} // namespace robot_name
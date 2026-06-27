#pragma once

#include <string>
#include <utility>

namespace robot_simulator {

enum class Bearing {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

class Robot {
public:
    Robot();
    Robot(std::pair<int, int> position, Bearing bearing);

    std::pair<int, int> get_position() const;
    Bearing get_bearing() const;

    void turn_right();
    void turn_left();
    void advance();

    void execute_sequence(const std::string& sequence);

private:
    std::pair<int, int> pos;
    Bearing direction;
};

} // namespace robot_simulator
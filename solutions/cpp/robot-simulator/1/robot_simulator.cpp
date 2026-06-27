#include "robot_simulator.h"

namespace robot_simulator {

Robot::Robot() : pos({0, 0}), direction(Bearing::NORTH) {}

Robot::Robot(std::pair<int, int> position, Bearing bearing) 
    : pos(position), direction(bearing) {}

std::pair<int, int> Robot::get_position() const {
    return pos;
}

Bearing Robot::get_bearing() const {
    return direction;
}

void Robot::turn_right() {
    // Rotação horária: NORTH (0) -> EAST (1) -> SOUTH (2) -> WEST (3)
    int current = static_cast<int>(direction);
    direction = static_cast<Bearing>((current + 1) % 4);
}

void Robot::turn_left() {
    // Rotação anti-horária
    int current = static_cast<int>(direction);
    direction = static_cast<Bearing>((current + 3) % 4);
}

void Robot::advance() {
    switch (direction) {
        case Bearing::NORTH: pos.second++; break;
        case Bearing::SOUTH: pos.second--; break;
        case Bearing::EAST:  pos.first++;  break;
        case Bearing::WEST:  pos.first--;  break;
    }
}

void Robot::execute_sequence(const std::string& sequence) {
    for (char command : sequence) {
        switch (command) {
            case 'R': turn_right(); break;
            case 'L': turn_left();  break;
            case 'A': advance();    break;
            default:  break;
        }
    }
}

} // namespace robot_simulator
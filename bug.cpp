#include "Bug.h"
#include <iostream>

// Constructor definition
Bug::Bug(int id, const std::pair<int, int>& position, int direction, int size, bool alive, const std::list<std::pair<int, int>>& path)
        : id(id), position(position), direction(direction), size(size), alive(alive), path(path) {}

// Check if the bug's way is blocked
bool Bug::isWayBlocked() const {
    int boardWidth = 10;
    int boardHeight = 10;

    switch (direction) {
        case 1: // North
            return position.second <= 0;
        case 2: // East
            return position.first >= boardWidth;
        case 3: // South
            return position.second >= boardHeight;
        case 4: // West
            return position.first <= 0;
        default:
            return false;
    }
}

// Check if the bug's ID matches the given ID
bool Bug::isIdSame(int otherId) const {
    return id == otherId;
}

// Get the bug's movement history
std::string Bug::bugHistory() const {
    std::string final = std::to_string(id) + " " + type + " Path: ";
    for (const auto& pos : path) {
        final += "(" + std::to_string(pos.first) + ", " + std::to_string(pos.second) + "), ";
    }

    std::string status = alive ? "Alive!" : "Dead!";
    final += status + "\n";

    return final;
}

// Output the bug's movement history
void Bug::outputBugHistory() const {
    std::cout << bugHistory();
}

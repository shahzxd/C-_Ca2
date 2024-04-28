#include "Bug.h"
#include <iostream> // Include necessary headers
#include <string>
#include <utility>
#include <list>

Bug::Bug(int id, std::pair<int, int> position, int direction, int size, bool alive, std::list<std::pair<int, int>> path) {
    this->id = id;
    this->position = position;
    this->direction = direction;
    this->size = size;   //1 - 20
    this->alive = alive;
    this->path = path;
}

bool Bug::isWayBlocked() const { // Declare as const
    int boardWidth = 10;
    int boardHeight = 10;

    switch(direction) {
        case 1:
            if (position.second <= 0) {
                return true;
            }
            break;
        case 2:
            if (position.first >= boardWidth) {
                return true;
            }
            break;
        case 3:
            if (position.second >= boardHeight) {
                return true;
            }
            break;
        case 4:
            if (position.first <= 0) {
                return true;
            }
            break;
        default:
            break;
    }

    return false;
}

bool Bug::isIdSame(int otherId) const { // Declare as const, rename parameter
    return this->id == otherId;
}

std::string Bug::bugHistory() const { // Declare as const
    std::string final = std::to_string(id) + " " + type + " Path: ";
    for (std::list<std::pair<int, int>>::const_iterator it = path.cbegin(); it != path.cend(); ++it) {
        final += "(" + std::to_string(it->first) + ", " + std::to_string(it->second) + "), ";
    }

    std::string status = "Alive!";
    if (!alive) {
        status = "Dead!";
    }

    final += status + "\n";

    return final;
}

void Bug::outputBugHistory() const {
    std::cout << bugHistory();
}

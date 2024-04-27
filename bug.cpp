#include "Bug.hpp"

// Constructor
Bug::Bug(int id, std::pair<int, int> position, int direction, int size)
        : id(id), position(position), direction(direction), size(size), alive(true) {}

// Destructor
Bug::~Bug() {}

// Function to check if the bug's way is blocked
bool Bug::isWayBlocked() {
    // Implement logic to check if the bug is against an edge of the board
    // and if it is facing in the direction of that edge.
}

// Getter functions
int Bug::getId() const {
    return id;
}

std::pair<int, int> Bug::getPosition() const {
    return position;
}

int Bug::getDirection() const {
    return direction;
}

int Bug::getSize() const {
    return size;
}

bool Bug::isAlive() const {
    return alive;
}

std::list<std::pair<int, int>> Bug::getPath() const {
    return path;
}

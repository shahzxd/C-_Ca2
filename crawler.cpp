#ifndef CRAWLER_H
#define CRAWLER_H

#include <iostream>
#include <list>
#include <utility>

class Crawler {
private:
    int id;
    std::pair<int, int> position;
    int direction;
    int size;
    bool alive;
    std::list<std::pair<int, int>> path;
    std::string type;

public:
    // Constructor
    Crawler(int id, std::pair<int, int> position, int direction, int size, bool alive, const std::list<std::pair<int, int>>& path);

    // Member functions
    void move();
    void outputBug() const;
};

#endif // CRAWLER_H

// Constructor definition
Crawler::Crawler(int id, std::pair<int, int> position, int direction, int size, bool alive, const std::list<std::pair<int, int>>& path)
        : id(id), position(position), direction(direction), size(size), alive(alive), path(path), type("Crawler") {}

// Member function to move the crawler
void Crawler::move() {
    while (Bug::isWayBlocked()) {
        direction = (std::rand() % 4) + 1;
    }

    switch (direction) {
        case 1: // North
            --position.second;
            break;
        case 2: // East
            ++position.first;
            break;
        case 3: // South
            ++position.second;
            break;
        case 4: // West
            --position.first;
            break;
        default:
            break;
    }

    path.emplace_back(position);
}

// Member function to output crawler information
void Crawler::outputBug() const {
    std::string status = alive ? "Alive" : "Dead";
    std::cout << "ID: " << id << ", Type: " << type << ", Position: (" << position.first << ", " << position.second
              << "), Size: " << size << ", Direction: " << direction << ", Status: " << status << std::endl;
}

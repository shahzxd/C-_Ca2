#ifndef BUG_HPP
#define BUG_HPP

#include <iostream>
#include <list>
#include <utility>

class Bug {
public:
    // Constructor
    Bug(int id, std::pair<int, int> position, int direction, int size);

    // Destructor
    virtual ~Bug();

    // Pure virtual function for moving the bug
    virtual void move() = 0;

    // Function to check if the bug's way is blocked
    bool isWayBlocked();

    // Getter functions
    int getId() const;
    std::pair<int, int> getPosition() const;
    int getDirection() const;
    int getSize() const;
    bool isAlive() const;
    std::list<std::pair<int, int>> getPath() const;

protected:
    int id;
    std::pair<int, int> position;
    int direction;
    int size;
    bool alive;
    std::list<std::pair<int, int>> path;
};

#endif // BUG_HPP

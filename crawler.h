#ifndef CRAWLER_H
#define CRAWLER_H

#include "Bug.h"
#include <list>
#include <utility>

class Crawler : public Bug {
public:
    Crawler(int id = 0, std::pair<int, int> position = {0, 0}, int direction = 1, int size = 1, bool alive = true, std::list<std::pair<int, int>> path = {});

    void move() override;
    void outputBug() const override;

private:
    std::pair<int, int> position;
    int id;
};

#endif // CRAWLER_H

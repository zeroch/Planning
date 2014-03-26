#ifndef ASTAR_H
#define ASTAR_H
#include "algorithm.h"
#include "vector"
class Astar : public Algorithm
{
public:
    Astar(Space * problem);
    ~Astar();
    void run();
    void pause();
    void stop();
    void runUntil();
    Path * pathGenerated();
    Path * areaExplored();
private:
    int heuristic(Point * currentLoc);

    Point * target;

    struct node{
        Point * currentPoint;
        node * previousNode;
        std::vector<node *> nextNodes;
    };

    node * head;
    node * tail;
};

#endif // ASTAR_H

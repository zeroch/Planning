#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "path.h"
#include "space.h"
class Algorithm : public QObject
{
    Q_OBJECT
public:
    Algorithm(Space * problem, int deltaq = 1);
    virtual ~Algorithm(){};
    virtual Path * pathGenerated() = 0;
    virtual Path * areaExplored() = 0;
public slots:
    virtual void run() = 0;
    virtual void pause() = 0;
    virtual void stop() = 0;
    virtual void runUntil() = 0;
protected:
	Space * all_points;
	double deltaq;

};
#endif  // ALGORITHM_H

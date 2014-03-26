#ifndef SPACE_H
#define SPACE_H
#include "point.h"
#include <cmath>
#include <QImage>
#include <vector>
class Space{
public:
	Space();
	virtual ~Space();
	virtual void initFromImage(const char*)=0;
	virtual void add_point(Point *);
	virtual double distance(Point * x, Point * y);
	virtual Point * randomPoint();
	virtual void update();
	virtual Point * findPoint(int*);
	virtual int get_dimension();
    virtual Point * get_start();
    virtual Point * get_end();
    virtual void set_start(int*) = 0;
    virtual void set_end(int*) = 0;
	virtual bool get_updated();
    virtual int get_maxDimension(int dimension);
    virtual void printSpace();//should consider changing this to override of << operator
    virtual std::vector<Point *> getNeighbors(Point *);
    virtual QImage & get_image() = 0;
protected:
	int num_dimension;
	bool updated;
    Point *start;
    Point *end;
	int * maxValuePerDimension;
};
#endif // SPACE_H

#ifndef SPACE2D_H
#define SPACE2D_H
#include "space.h"
#include "point2d.h"
#include <vector>
#include <iostream>
#include <string.h>
#include <QImage>
#include <QObject>
class Space2D :  public QObject, public Space
{
    Q_OBJECT
public:
    Space2D();
	virtual ~Space2D();
	void add_point(Point2D*);
    void initFromImage(const char*);
	void printSpace();
    Point * randomPoint();
    Point * findPoint(int*);
    int get_maxDimension(int dimension);
    void set_start(int*);
    void set_end(int*);
    Point * get_start();
    Point * get_end();
    std::vector<Point *> getNeighbors(Point *);
    int get_dimension();
    QImage & get_image();
private:
    std::vector<Point2D *> *worldMap;
    int maxValuePerDimension[2];
    QImage *m_rawImage;
    /* data */
};


#endif // SPACE2D_H

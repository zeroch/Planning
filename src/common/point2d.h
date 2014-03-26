#ifndef POINT2D_H
#define POINT2D_H
#include "point.h"
#include <array>
#include <iostream>
class Point2D : public Point
{
public:
	Point2D();
	Point2D(int * coordinate_, bool traversable_, int type_);
	Point2D(std::array<int ,2> coordinate_, bool traversable_, int type_);
	Point2D& operator=(const Point2D &rhs);
	~Point2D();
	void set_coordinate(int *coordinates_);
	int get_coordinate(int x_coor);
	std::array<int ,2> get_coordinates();
	bool valid();

	/* data  inheritance from Point(parent)*/
private:
	std::array< int, 2> coordinates;

};


#endif

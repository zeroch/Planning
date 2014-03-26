#ifndef POINT_H
#define POINT_H
#include "string.h"
#include <iostream>

class Point
{
public:
	Point();
	Point(int num_d) : num_dimemsion(num_d) {};
	virtual ~Point();
	Point& operator=(const Point &rhs);
	void set_dimemsion(int num_d);
	int get_dimemsion();

	virtual void set_coordinate(int *_coordinates);
	virtual int get_coordinate(int x_coor);

	void set_valid(bool valid_);
	void set_type(int);
	bool valid();
	/* data */
	// type hold 0, 1, 2 for normal, start ,end.
protected:
	bool traversable;
	int type;
	int num_dimemsion;
	int * coordinates;
};
#endif  // POINT_H

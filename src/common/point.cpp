#include "point.h"

Point::Point(){
	traversable = false;
	num_dimemsion = 0;

}
Point::~Point(){
	
}

Point& Point::operator= (const Point &rhs){
	traversable = rhs.traversable;
	type = rhs.type;
	num_dimemsion = rhs.num_dimemsion;
	memcpy(coordinates, rhs.coordinates,sizeof(int)*num_dimemsion);
	return *this;
}
void Point::set_dimemsion(int num_d){
	num_dimemsion = num_d;
}
int Point::get_dimemsion(){
	return num_dimemsion;
}

void Point::set_coordinate(int *_coordinates){
	for (int i = 0; i < num_dimemsion; ++i)
	{
		*(coordinates+i) = *(_coordinates+i);
	}
}
int Point::get_coordinate(int x_coor){
	return coordinates[x_coor];
}
void Point::set_valid(bool valid_){
	traversable = valid_;
}
void Point::set_type(int type_){
	type = type_;
}
bool Point::valid(){
	return traversable;
}


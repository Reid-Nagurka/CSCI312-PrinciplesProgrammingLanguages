#include <iostream>
#include <string>
#include <cmath>
#include "point.h"

using namespace std;

Point::Point () {}
Point::Point (double x, double y, double z) { set (x, y, z); }

void Point::set (double x, double y, double z) {this -> x = x; this -> y = y; this -> z = z;}

double Point::length ()
{
    return sqrt ( (x * x) + (y * y) + (z * z ));
}

Point Point::operator- (Point& p)
{
    Point r;
    r.set(x - p.x, y - p.y, z - p.z);
    return r;
}

void Point::print (void)
{
    cout<<"Location: x: "<<x<< " y: "<<y<< " z: "<<z <<"\n";
}



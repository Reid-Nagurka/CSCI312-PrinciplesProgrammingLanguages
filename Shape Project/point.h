#ifndef POINT_H
#define POINT_H

#include <string>

using namespace std;


class Point{

   private:
      double x;
      double y;
      double z;    

   public:
      Point ();
      Point (double x, double y, double z);

      void set (double x, double y, double z);

      double length ();

      Point operator- (Point& p);

      void print (void);
};


#endif
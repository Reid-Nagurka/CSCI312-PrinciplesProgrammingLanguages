#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include "point.h"

using namespace std;


class Shape{

   private:
      Point loc;
      string type;
    
    protected:
      string color;

   public:
      Shape * next;

      Shape (string type, string color, Point loc);

      virtual void print_color (void);

      virtual double compute_volume (void) = 0;

      void print_type (void);

      void print_loc (void);
};

#endif

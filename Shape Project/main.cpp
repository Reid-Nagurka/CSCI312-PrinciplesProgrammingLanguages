#include <string>
#include <iostream>
#include "shape.h"
#include "point.h"
#include "sphere.h"
#include "cone.h"
#include "box.h"

using namespace std;


void read_objs (Shape **list)

{
   Shape *node;         // variable used to create a new node each time through the loop
   double x, y, z, xx, yy, zz, rad, length, width, height; 
   string type, color, color2, tbcolor, bcolor;
   Point center, loc, apex;

   // initialize list
   *list = NULL;

   while (cin >> type) {

      if (type.compare ("sphere") == 0) {

         // fill in code here to read in the sphere values and create a new node
         cin >> x >> y >> z >> rad >> color; 
         node = new Sphere (type, color, Point (x, y, z), rad);
      }

      else if (type.compare ("box") == 0) {

         // fill in code here to read in the box values and create a new node
         cin >> length >> width >> height >> x >> y >> z >> color >> tbcolor;
         node = new Box (type, color, tbcolor, length, width, height, Point (x, y, z) );
      }
   
      else if (type.compare ("cone") == 0) {

         cin >> x >> y >> z >> xx >> yy >> zz >> rad >> color >> color2;

         node = new Cone (type, color, color2, Point (x, y, z), Point (xx, yy, zz), rad);
      }

      // link new node at front of list:
      //   set the next field of node to the beginning of the list (*list)
      node -> next = *list;
      //   set the beginning of the list to node
      *list = node;
   }
}

void print_objs (Shape *list)
{
    
    Shape* node;
    node = list;
    cout<<"Objects:\n\n";
    while (node != NULL)
    {
        node -> print_type();
        node -> print_color();
        //only need to print new line here b/c did not want to change cone.cpp by adding a new line in the implementation of print color
        cout<<"\n";
        node -> print_loc(); 
    
        cout<<"Volume: "<<node -> compute_volume()<<"\n\n";
        node = node -> next;
    }
    
}



int main()
{
    Shape* list;
    read_objs (&list);
    print_objs (list);

    //return memory
    Shape* node = list;
    Shape* tmp;
    while (node != NULL)
    {
        
        tmp = node;  
        delete tmp;
        node = node -> next;
    }

    return (0);
}
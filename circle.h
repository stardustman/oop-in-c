#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "shape.h"

/* Circle's attributes...*/

typedef struct {
    Shape super; /* <== inherits Shape*/

    /* attributes added by this subclass...*/
     int radius;
} Circle;

/* constructor prototype*/
void Circle_ctor(Circle * const me,int x,int y ,int radius);


#endif // CIRCLE_H_INCLUDED

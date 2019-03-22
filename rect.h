#ifndef RECT_H_INCLUDED
#define RECT_H_INCLUDED

#include "shape.h"
/* Rectangle's attributes...*/

typedef struct {
    Shape super; /* <== inherits Shape*/

    /* attributes added by this subclass...*/
     unsigned int width;
     unsigned int height;
} Rectangle;

/* constructor prototype*/
void Rectangle_ctor(Rectangle * const me,int x,int y ,unsigned int width,unsigned int height);


#endif // RECT_H_INCLUDED

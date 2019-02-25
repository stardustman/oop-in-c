#include "circle.h"
#include <stdio.h>
/* Circle's prototype of its virtual functions*/
/* Note: the "me" pointer has the type of the superclass to fit the vtable*/

static int Circle_area_(Shape const * const me);
static void Circle_draw_(Shape const * const me);


/* constructor implementation*/
void Circle_ctor(Circle * const me, int x,int y ,int radius)
{
    //vtbl of the Circle class
    static struct ShapeVtbl const vtbl = {
        &Circle_area_,
        &Circle_draw_
    };

    /* first call superclass's ctor*/
    Shape_ctor(&me->super,x, y);

    //override the vptr*
    me->super.vptr = &vtbl;

     /*initialize the attributes added by this subclass..*/
    me->radius = radius;
}

// Circle's class implementations of its virtual functions
static int Circle_area_(Shape const * const me){
    //explicit downcast
    Circle const* const me_ = (Circle const *)me;
    return (int)me_->radius * (int)me_->radius * 3.14;

}

static void Circle_draw_(Shape const * const me){
    Circle const* const me_ = (Circle const *)me;
    printf("Circle_draw_ (radius=%d)\n",me_->radius);
}

#include "rect.h"
#include <stdio.h>

/* Rectangle's prototype of its virtual functions*/
/* Note: the "me" pointer has the type of the superclass to fit the vtable*/

static int Rectangle_area_(Shape const * const me);
static void Rectangle_draw_(Shape const * const me);


/* constructor implementation*/
void Rectangle_ctor(Rectangle * const me, int x, int y, unsigned int width,unsigned int height)
{
    //vtbl of the Rectangle class
    static struct ShapeVtbl const vtbl = {
        &Rectangle_area_,
        &Rectangle_draw_
    };

    /* first call superclass's ctor*/
    Shape_ctor(&me->super, x , y);

    //override the vptr*
    me->super.vptr = &vtbl;


    /*initialize the attributes added by this subclass..*/
    me->width = width;
    me->height = height;
}

// Rectangle's class implementations of its virtual functions
static int Rectangle_area_(Shape const * const me){
    //explicit downcast
    Rectangle const* const me_ = (Rectangle const *)me;
    return (int)me_->width * (int)me_->height;

}

static void Rectangle_draw_(Shape const * const me){
    Rectangle const* const me_ = (Rectangle const *)me;
    printf("Rectangle_draw_ (x=%d,y=%d,width=%d,height=%d)\n",me_->super.x,me_->super.y,me_->width,me_->height);
}

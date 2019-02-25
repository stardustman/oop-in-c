#include "shape.h"  /* Shape class interface */
#include <assert.h>


/* Shape's prototype of its virtual functions*/
static int Shape_area_(Shape const * const me);
static void Shape_draw_(Shape const * const me);

/* constructor implementation*/
void Shape_ctor(Shape * const me, int x, int y){
    //vtbl of the Shape class
    static struct ShapeVtbl const vtbl = {
        &Shape_area_,
        &Shape_draw_
    };

   // "hook" the vptr to the vtbl
   me->vptr = &vtbl;
   me->x = x;
   me->y = y;
}

void Shape_moveBy(Shape * const me, int dx, int dy){
    me->x += dx;
    me->y += dy;
}

int Shape_getX(Shape * const me){
    return me->x;
}

int Shape_getY(Shape * const me){
    return me->y;
}

// Shape class implementations of its virtual functions

static  int Shape_area_(Shape const* const me){
    //purely-virtual function should never be called
    assert(0);
    //to avoid compiler warnings
    return 0U;
}

static void Shape_draw_(Shape const* const me){
    //purely-virtual function should never be called
    assert(0);
}

/* find the largest-area shape in the collection*/
Shape const* largestShape(Shape const* shapes[], int nShapes){
   Shape const *s = (Shape*)0;
   int max = 0U;
   int i;

   for(i = 0U; i < nShapes; ++i){
    //virtual call
    int area = Shape_area(shapes[i]);
    if(area > max){
        max = area;
        s = shapes[i];
    }
   }
   // the largest shape in the array shapes[]
   return s;
}

// draw all shapes on the screen

void drawAllShapes(Shape const* shapes[], int nShapes){
    int i;
    for(i=0U; i < nShapes; i++){
        //virtual call
        Shape_draw(shapes[i]);
    }

}




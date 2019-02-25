#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED

#include <stdint.h>



/* forward declaration */
struct ShapeVtble;

/*  Shape's attribute..  */
typedef struct {

    //--->Shape's virtual Pointer for per Object, immutable object
    struct ShapeVtbl const * vptr;

    // x-coordinate of Shape's position
    int x;
    // y-coordinate of Shape's position
    int y;
} Shape;

//--->Shape's virtual table  for per Class
struct ShapeVtbl{
    //pointer to function area
    int (*area) (Shape const * const me);
    //pointer to function draw
    void (*draw)(Shape const * const me)
};


/*  Shape's operations  (Shape's interface) */

void Shape_ctor(Shape * const me, int x, int y);
void Shape_moveBy(Shape * const me, int x, int y);
int Shape_getX(Shape * const me);
int Shape_getY(Shape * const me);


static inline int Shape_area(Shape const * const me){
    return (*me->vptr->area)(me);
}

static inline void Shape_draw(Shape const * const me){
    return (*me->vptr->draw)(me);
}

//generic operation on collections of Shapes
Shape const *largestShape(Shape const* shapes[],int nShapes);
void drawAllShapes(Shape const *shapes[],int nShapes);






#endif // SHAPE_H_INCLUDED

#include "widgets.hpp"
#include "Field.h"
#include "graphics.hpp"

const static int SIZE = 25;

Field::Field(Application * w,int x, int y) : Widget(w, x, y, SIZE, SIZE)
{

}
void Field::draw()
{
    using namespace genv;

    gout << move_to(_x, _y) << color(255,255,255) << box(SIZE, SIZE);
    gout << move_to(_x + 1, _y + 1) << color(0,0,0) << box(SIZE-2, SIZE-2);
}
void Field::handle(genv::event ev)
{

}

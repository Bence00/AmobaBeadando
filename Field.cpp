#include "widgets.hpp"
#include "Field.h"
#include "graphics.hpp"
#include "iostream"
#include "math.h"

const static int SIZE = 25;

Field::Field(Application * w,int x, int y, std::function<void()> _render) : Widget(w, x, y, SIZE, SIZE)
{
    ColorManagment = 50;
    BusyField = false;
    PlayerOne = true;
    render = _render;
}
void Field::draw()
{
    using namespace genv;
    render();

}

void Field::handle(genv::event ev)
{
    using namespace genv;
    if(ev.pos_x >= _x && ev.pos_y>= _y && ev.pos_x <= _x + SIZE && ev.pos_y <= _y + SIZE);
}

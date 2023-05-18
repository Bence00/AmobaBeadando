#include "button.h"
#include "graphics.hpp"
#include "iostream"

Button::Button(Application * w,int x, int y, int sx, int sy)
                 : Widget(w, x, y, sx, sy)
{
    _size_x=sx;
    _size_y=sy;
    _value = 1;
}

void Button::draw() {

    using namespace genv;

    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+1, _y+1) << color(asd*255,0,0) << box(_size_x-2, _size_y-2);
}

void Button::handle(genv::event ev)
{
    using namespace genv;

    if (ev.type == ev_mouse)
    {
        if (ev.button==btn_left && ev.pos_x >= _x && ev.pos_x <= _x + _size_x - 1 &&
           ev.pos_y >=_y && ev.pos_y < _y + _size_y)
            {
              _value+=1;
              asd=!asd;
            }
    }
}




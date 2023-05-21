#include "button.h"
#include "graphics.hpp"
#include "iostream"

Button::Button(Application * w,int x, int y, int sx, int sy,std::function<void()> f)
                 : Widget(w, x,y,sx,sy), _f(f)
{
    _size_x=sx;
    _size_y=sy;
    _x=x;
    _y=y;
}

void Button::draw() {

    using namespace genv;

    gout<<color(255,255,255)<<move_to(_x,_y)<<box(_size_x,_size_y)
        <<color(0,0,0)<<move_to(_x+_size_x/2-gout.twidth("RESTART!")/2,_y+_size_y/2+_size_y/6/2+gout.cascent()/2)<<text("RESTART!");

   /* gout<<color(50,50,50)<<move_to(_x+_size_x/4,_y+_size_y/2)<<box(_size_x/2,_size_y/6)
        <<color(255,255,255)<<move_to(_x+_size_x/4+2,_y+_size_y/2+2)<<box(_size_x/2-2,_size_y/6-2)
        <<color(0,0,0)<<move_to(_x+_size_x/2-gout.twidth("RESTART!")/2,_y+_size_y/2+_size_y/6/2+gout.cascent()/2)<<text("RESTART!");*/
}

void Button::handle(genv::event ev)
{
    using namespace genv;
    std::cout<<"asd"<<std::endl;

    if (ev.type == ev_mouse)
    {
        std::cout<<"asd"<<std::endl;
        if (ev.button==btn_left)
        {
            _f();
        }
    }
}




#include "widgets.hpp"
#include "graphics.hpp"
#include "iostream"
#include "Menu.h"

Menu::Menu(Application * w,int x, int y, int sx, int sy, int _size, bool isPlayerX) : Widget(w,x,y,sx,sy)
{
    _x = x;
    _y = y;
    _isPlayerX = isPlayerX;
    this -> _size = _size;

};
void Menu::draw() {

    using namespace genv;
    gout<<move_to(_x,_y)<<color(0,0,0)<<box(2*_size,_size)<<move_to(_x+1,_y+1)<<color(0,100,100)<<box(2*_size-2,_size-2);
    if(_isPlayerX)
    {
        gout<<color(100,10,150)<<move_to(_x/2-gout.twidth("Player1 won!"),_y/2)<<text("Player1 Won");
    }
    else
    {
        gout<<color(100,10,150)<<move_to(_x/2-gout.twidth("Player2 won!"),_y/2)<<text("Player2 Won");
    }

}

void Menu::handle(genv::event ev)
{
    using namespace genv;

}








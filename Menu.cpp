#include "widgets.hpp"
#include "graphics.hpp"
#include "iostream"
#include "Menu.h"
#include "button.h"

Menu::Menu(Application* w, int x, int y, int sx, int sy, bool isPlayerX, std::function<void()> resetMethod) : Widget(w,x,y,sx,sy)
{
    _x = x;
    _y = y;
    _size_x=sx;
    _size_y=sy;
    _isPlayerX = isPlayerX;
    new Button(w, _x+_size_x/4, _y+_size_y/2+2, _size_x/2-2, _size_y/6-2, resetMethod);

};
void Menu::draw() {

    using namespace genv;

    gout<<move_to(_x,_y)<<color(80,80,80)<<box(_size_x,_size_y)
        <<move_to(_x+3,_y+3)<<color(100,100,100)<<box(_size_x-3,_size_y-3);

    if(_isPlayerX)
    {
        gout<<color(255,255,255)<<move_to(_x+_size_x/2-gout.twidth("PLAYER1 WON!")/2,_y+_size_y/3)<<text("PLAYER1 WON!");
    }
    else
    {
        gout<<color(255,255,255)<<move_to(_x+_size_x/2-gout.twidth("PLAYER2 WON!")/2,_y+_size_y/3)<<text("PLAYER2 WON!");
    }

}
void Menu::handle(genv::event ev)
{
    using namespace genv;



}







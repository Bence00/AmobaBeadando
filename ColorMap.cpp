#include "widgets.hpp"
#include "ColorMap.h"
#include "graphics.hpp"

ColorMap::ColorMap(Application * w,int x, int y, int sx, int sy) :  Widget(w, x, y, sx, sy)
{
    _size_x=sx;
    _size_y=sy;

    r = 0;
    g = 0;
    b = 0;
}
void ColorMap::draw()
{
    using namespace genv;

    gout << move_to(_x, _y) << color(0,255,255) << box(20, 20);
    gout << move_to(_x + 1, _y + 1) << color(20,0,0) << box(20-2, 20-2);
}
void ColorMap::handle(genv::event ev)
{
    for(int x = 0; x < _size_x; x++)
    {
        for(int y = 0; y < _size_y; y++)
        {

        }
    }

}

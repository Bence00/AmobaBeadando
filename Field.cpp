#include "widgets.hpp"
#include "Field.h"
#include "graphics.hpp"
#include "iostream"
#include "math.h"
#include "RenderUtility.h"

const static int SIZE = 25;

Field::Field(Application * w,int x, int y, std::function<void()> _render) : Widget(w, x, y, SIZE, SIZE)
{
    ColorManagment = 50;
    isBusy = false;
    render = _render;
}
void Field::draw()
{
    using namespace genv;
    render();
}

void Field::handle(genv::event ev)
{

}

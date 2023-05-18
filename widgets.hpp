#pragma once

#include "graphics.hpp"

class Application;

class Widget{
protected:

    int _x, _y, _size_x, _size_y;
    Application * _w;

public:
    Widget(Application * w,int x, int y, int sx, int sy);

    virtual void draw() = 0;
    virtual void handle(genv::event ev) = 0;

    bool is_selected(int mouse_x, int mouse_y);


};


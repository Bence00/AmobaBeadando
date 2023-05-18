#pragma once
#include "widgets.hpp"

class ColorMap : public Widget
{
private:
    int r, g, b;

public:

    ColorMap(Application * w,int x, int y, int sx, int sy);

    void draw();
    void handle(genv::event ev);
};


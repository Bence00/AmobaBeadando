#pragma once
#include "graphics.hpp"

class RenderUtility
{
public:

    void DrawCircle(int _x, int _y, int _size);
    void DrawX(int _x, int _y, int _size);
    void DrawBlank(int _x, int _y, int _size);
    void DrawCircleWin(int WindowCenterX, int WindowCenterY, int _size);
    void DrawXWin(int WindowCenterX, int WindowCenterY, int _size);
};

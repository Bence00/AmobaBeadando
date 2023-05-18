#include "RenderUtility.h"
#include "graphics.hpp"
#include "math.h"

void RenderUtility::DrawCircle(int _x, int _y, int _size)
{
    using namespace genv;

    int centerX = _x + _size / 2;
    int centerY = _y + _size / 2;

    int radius = _size / 3;

    gout << move_to(centerX + radius, centerY);
    for (int angle = 0; angle <= 360; angle++) {

        float radians = angle * M_PI / 180;

        int pointX = centerX + static_cast<int>(radius * cos(radians) + 0.5);
        int pointY = centerY + static_cast<int>(radius * sin(radians) + 0.5);

        gout<<color(255,0,0) << line_to(pointX, pointY);
    }

}
void RenderUtility::DrawX(int _x, int _y, int _size)
{
    using namespace genv;

    gout << move_to(_x + 5, _y + 5) << color(200,0,0) << line_to(_x + _size - 5, _y + _size - 5);
    gout << move_to(_x + _size - 5, _y + 5) << color(200,0,0) << line_to(_x + 5, _y + _size - 5);

}
void RenderUtility::DrawBlank(int _x, int _y, int _size)
{
    using namespace genv;

    gout << move_to(_x, _y) << color(255,255,255) << box(_size, _size);
    gout << move_to(_x + 1, _y + 1) << color(0,0,0) << box(_size-2, _size-2);
}

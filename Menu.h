#pragma once
#include "widgets.hpp"
#include "iostream"
#include "functional"

class Menu : public Widget
{
private:

    bool _isPlayerX;
public:

    Menu(Application* w,int x, int y, int sx, int sy, bool isPlayerX, std::function<void()> resetMethod);
    void DrawWin(int WindowCenterX, int WindowCenterY, bool isPlayerX);
    void handle(genv::event ev);
    void draw();
};

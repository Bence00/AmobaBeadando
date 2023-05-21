#pragma once
#include "widgets.hpp"
#include "iostream"

class Menu : public Widget
{
private:
    int _size;
    bool _isPlayerX;
public:
    Menu(Application * w,int x, int y, int sx, int sy, int _size, bool isPlayerX);
    void DrawWin(int WindowCenterX, int WindowCenterY, int _size, bool isPlayerX);
   void handle(genv::event ev);
    void draw();
};

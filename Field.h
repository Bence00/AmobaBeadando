#pragma once
#include "widgets.hpp"
#include "iostream"
#include <functional>
class Field : public Widget {
private:
    int ColorManagment;
    bool isBusy;
    bool PlayerOne;


public:
    Field(Application * w,int x, int y, std::function<void()> render);

    static const int SIZE = 25;

    void draw();
    void handle(genv::event ev);

    std::function<void()> render;

    void SetRender(std::function<void()> render)
    {
        this->render = render;
    }
    int GetPosX()
    {
        return _x;
    }
    int GetPosY()
    {
        return _y;
    }
    bool GetIsBusy(){
        return isBusy;
    }
    void SetIsBusy(bool isBusy){
        this->isBusy = isBusy;
    }
 };

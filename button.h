#pragma once
#include <functional>
#include "widgets.hpp"

class Button : public Widget {
private:
    std::function<void()> _f;
public:
    Button(Application* w,int x, int y, int sx, int sy, std::function<void()> f);
    void handle(genv::event ev);
    void draw();
};


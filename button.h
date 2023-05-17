#pragma once

#include "graphics.hpp"
#include "widgets.hpp"

class Button : public Widget {
private:

    int _value;
    int _checker;
    bool asd;


public:
    Button(Application * ptr,int x, int y, int sx, int sy);
    void handle(genv::event ev);
    void draw();
    bool changedValue();
    virtual std::string logvalue();
 };


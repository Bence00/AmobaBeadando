#pragma once
#include "widgets.hpp"

class Field : public Widget {
private:

public:
    Field(Application * ptr,int x, int y);
    static const int SIZE = 25;
    void draw();
    void handle(genv::event ev);
 };

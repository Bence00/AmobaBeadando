#pragma once

#include <vector>
#include "widgets.hpp"
#include <fstream>

class Application
{
private:
    std::vector<Widget*> widgets;
public:
    void RegisterWidget (Widget *w)
    {
        widgets.push_back(w);
    }
    Application();

    //virtual ~Application();

    void update();
    void Start();

};



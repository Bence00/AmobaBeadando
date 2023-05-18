#pragma once

#include <vector>
#include "widgets.hpp"
#include <fstream>

class Application
{
private:
    std::vector<Widget*> widgets;
    void Update();
    void Setup();
    void Draw();
    void Logic();
public:
    void RegisterWidget (Widget *w)
    {
        widgets.push_back(w);
    }
    Application();

    //virtual ~Application();

    void Start();

};



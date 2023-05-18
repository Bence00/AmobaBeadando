#pragma once
#include <vector>
#include "widgets.hpp"
#include "Field.h"
#include <fstream>

class Application
{
private:
    static const int MapSize = 15;
    std::vector<Widget*> widgets;
    Field* fields[MapSize][MapSize];
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



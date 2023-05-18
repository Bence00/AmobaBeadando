#pragma once
#include <vector>
#include "widgets.hpp"
#include "Field.h"
#include "ColorMap.h"
#include <fstream>

class Application
{
private:
    std::vector<Widget*> widgets;
    static const int MapSize = 15;
    static const int InfoBarSize = 50;
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

    static int GetInfoBarSize()
    {
        return InfoBarSize;
    }

    static int GetMapSize()
    {
        return MapSize;
    }
    void Start();

};



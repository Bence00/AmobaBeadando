#pragma once
#include "widgets.hpp"
#include "Field.h"
#include "ColorMap.h"

class Application
{
private:

    std::vector<Widget*> widgets;
    std::function<void()> renderMethod;

    static const int MapSize = 15;
    static const int InfoBarSize = 10;

    Field* fields[MapSize][MapSize];

    void Setup();
    void Logic();
    void Update();
    void Draw();

    bool isPlayerX;

public:

    int FieldNumberToWin;

    void Start();
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


};



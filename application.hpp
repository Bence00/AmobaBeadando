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

    Field* fields[MapSize][MapSize];

    void Setup();
    void Logic();
    void Update();
    void Draw();

    bool isPlayerX;
    bool isRunning;

public:
    void Reset();

    int score[2];
    int FieldNumberToWin;

    void Start();
    void Win();
    Application();

    void RegisterWidget (Widget *w)
    {
        widgets.push_back(w);
    }

    static int GetMapSize()
    {
        return MapSize;
    }

};



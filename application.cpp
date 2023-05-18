#include "application.hpp"
#include "widgets.hpp"
#include "graphics.hpp"
#include "vector"
#include "iostream"
#include "RenderUtility.h"


static const int WindowWidth = Field::SIZE * Application::GetMapSize();
static const int WindowHeight = Field::SIZE * Application::GetMapSize() + Application::GetInfoBarSize();
static bool isPlayerX;

Application::Application(){
 isPlayerX = true;
}

void Application::Update()
{
    using namespace genv;
    event ev;
    int focus = -1;
    while(gin >> ev && ev.keycode != key_escape)
    {
        if (ev.type == ev_mouse && ev.button==btn_left)
        {
            for (size_t i=0;i<widgets.size();i++)
            {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y))
                {
                    focus = i;
                    break;
                }
                focus = -1;
            }

            for (int x = 0; x < MapSize; x++)
            {
                for (int y = 0; y < MapSize; y++)
                {
                    Field* selectedField = fields[x][y];
                    if (selectedField->is_selected(ev.pos_x, ev.pos_y)) {
                        if (!selectedField->GetIsBusy()) {
                            int xPos = Field::SIZE * x;
                            int yPos = Field::SIZE * y;
                            RenderUtility* r = new RenderUtility();
                            std::function<void()> renderMethod;
                            if (isPlayerX)
                            {
                                renderMethod = [r, xPos, yPos]() {r->DrawX(xPos, yPos, Field::SIZE); };
                            }
                            else
                            {
                                renderMethod = [r, xPos, yPos]() {r->DrawCircle(xPos, yPos, Field::SIZE); };
                            }
                            selectedField->SetRender(renderMethod);
                            selectedField->SetIsBusy(true);
                            isPlayerX = !isPlayerX;
                        }
                        break;
                    }
                }
            }
        }
        if (focus != -1)
        {
            widgets[focus]->handle(ev);
        }

        Logic();
        Draw();
    }
}
void Application::Start()
{
    Setup();
    Update();
}
void Application::Setup()
{
    genv::gout.open(WindowWidth,WindowHeight);

    for(int x = 0; x<MapSize;x++)
    {
        for(int y = 0; y<MapSize;y++)
        {
            int xPos = Field::SIZE * x;
            int yPos = Field::SIZE * y;
            RenderUtility* r = new RenderUtility();
            std::function<void()> renderMethod = [r, xPos, yPos]() {r->DrawBlank(xPos, yPos, Field::SIZE);};;
            fields[x][y] = new Field(this, xPos, yPos, renderMethod);

        }
    }
    Draw();
    //ColorMap* colormap;
    //colormap = new ColorMap(this, 20, WindowHeight-50, 40, 40);
}
void Application::Draw()
{
    for (Widget* w : widgets)
    {
        w->draw();
    }
    for(int x = 0; x < MapSize; x++)
    {
        for(int y = 0; y < MapSize; y++)
        {
            fields[x][y]->draw();
        }
    }
    genv::gout << genv::refresh;

}
void Application::Logic()
{

}


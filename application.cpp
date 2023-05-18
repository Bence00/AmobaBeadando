#include "application.hpp"
#include "widgets.hpp"
#include "graphics.hpp"
#include "vector"
#include "iostream"

static const int WindowWidth = 25 * 15;
static const int WindowHeight = 600;

Application::Application(){
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
            fields[x][y] = new Field(this, 25 * x, 25 * y + 1);
        }
    }
}
void Application::Draw()
{
    for (Widget* w : widgets)
    {
        w->draw();
    }
    for(int x = 0; x<MapSize;x++)
    {
        for(int y = 0; y<MapSize;y++)
        {
            fields[x][y]->draw();
        }
    }
    genv::gout << genv::refresh;

}
void Application::Logic()
{

}


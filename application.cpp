#include "application.hpp"
#include "widgets.hpp"
#include "graphics.hpp"
#include "iostream"

static const int WindowWidth = 800;
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
}
void Application::Draw()
{
     for (Widget* w : widgets)
        {
            w->draw();
        }
        genv::gout << genv::refresh;
}
void Application::Logic()
{

}


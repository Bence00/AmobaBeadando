#include "application.hpp"
#include "widgets.hpp"
#include "graphics.hpp"
#include "vector"
#include "iostream"
#include "RenderUtility.h"


static const int WindowWidth = Field::SIZE * Application::GetMapSize();
static const int WindowHeight = Field::SIZE * Application::GetMapSize() + Application::GetInfoBarSize();

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
                focus = -1;
            }
        }
        if (focus != -1)
        {
            widgets[focus]->handle(ev);
        }

        Logic();
        Draw();
        if (ev.type == ev_mouse && ev.button==btn_right)
        {
            RenderUtility* r = new RenderUtility();
            Field* field = fields[0][0];
            field->SetRender([r, field](){r->DrawX(field->GetPosX(), field->GetPosY(), field->SIZE);});
        }
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
            fields[x][y] = new Field(this, Field::SIZE * x, Field::SIZE * y, [this](){this->;});
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
void Application::test(std::string str){
    std::cout<<str<<std::endl;
}


#include "background.hpp"
#include "widgets.hpp"
#include "graphics.hpp"
#include "iostream"

void Application::event_loop()
{
    using namespace genv;
    event ev;
    int focus = -1;
    while(gin >> ev && ev.keycode != key_escape)
    {

        for (Widget* w : widgets)
        {
            w->draw();
        }

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

        gout << refresh;
    }
}



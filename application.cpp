#include "iostream"
#include "graphics.hpp"
#include "widgets.hpp"
#include "application.hpp"
#include "RenderUtility.h"
#include <typeinfo>

static const int WindowWidth = Field::SIZE * Application::GetMapSize();
static const int WindowHeight = Field::SIZE * Application::GetMapSize() + Application::GetInfoBarSize();

Application::Application()
{
    FieldNumberToWin = 5;
}
void Application::Update()
{
    using namespace genv;

    event ev;

    //int focus = -1;
    while(gin >> ev && ev.keycode != key_escape)
    {
        if (ev.type == ev_mouse && ev.button == btn_left)
        {
           /* for (size_t i=0;i<widgets.size();i++)
            {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y))
                {
                    focus = i;
                    break;
                }
                focus = -1;
            }*/
            for (int x = 0; x < MapSize; x++)
            {
                for (int y = 0; y < MapSize; y++)
                {
                    Field* selectedField = fields[x][y];
                    if (selectedField->is_selected(ev.pos_x, ev.pos_y))
                    {
                        if (!selectedField->GetIsBusy())
                        {
                            int xPos = Field::SIZE * x;
                            int yPos = Field::SIZE * y;

                            RenderUtility* r = new RenderUtility();

                            if (isPlayerX)
                            {
                                renderMethod = [r, xPos, yPos]() {r->DrawX(xPos, yPos, Field::SIZE); };
                            }
                            else
                            {
                                renderMethod = [r, xPos, yPos]() {r->DrawCircle(xPos, yPos, Field::SIZE);};
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
        Logic();
        Draw();
    }
}
void Application::Logic()
{
    for (int y = 0; y < MapSize; y++)
    {
        for (int x = 0; x <= MapSize - FieldNumberToWin; x++)
        {
            bool isWinningRow = true;
            for (int i = 0; i < FieldNumberToWin; i++)
            {
                Field* field = fields[x + i][y];

                if (!field->GetIsBusy() || field->GetRender().target_type() != renderMethod.target_type())
                {
                    isWinningRow = false;
                    break;
                }
            }
            if (isWinningRow)
            {
                isPlayerX ? (std::cout<<"O Win"<<std::endl) : (std::cout<<"X Win"<<std::endl)
                return;
            }
        }
    }

    for (int x = 0; x < MapSize; x++)
    {
        for (int y = 0; y <= MapSize - FieldNumberToWin; y++)
        {
            bool isWinningColumn = true;
            for (int i = 0; i < FieldNumberToWin; i++)
            {
                Field* field = fields[x][y + i];
                if (!field->GetIsBusy() || field->GetRender().target_type() != renderMethod.target_type())
                {
                    isWinningColumn = false;
                    break;
                }
            }
            if (isWinningColumn)
            {
               std::cout<<"WINNING COLUMN"<<std::endl;
               return;
            }
        }
    }

    for (int x = 0; x <= MapSize - FieldNumberToWin; x++)
    {
        for (int y = 0; y <= MapSize - FieldNumberToWin; y++)
        {
            bool isWinningDiagonal = true;
            for (int i = 0; i < 5; i++)
            {
                Field* field = fields[x + i][y + i];
                if (!field->GetIsBusy() || field->GetRender().target_type() != renderMethod.target_type())
                {
                    isWinningDiagonal = false;
                    break;
                }
            }
            if (isWinningDiagonal)
            {
                 std::cout<<"WINNING DIAGONAL1"<<std::endl;
                return;
            }
        }
    }

    for (int x = 4; x < MapSize; x++)
    {
        for (int y = 0; y <= MapSize - FieldNumberToWin; y++)
        {
            bool isWinningDiagonal = true;
            for (int i = 0; i < FieldNumberToWin; i++)
            {
                Field* field = fields[x - i][y + i];
                if (!field->GetIsBusy() || field->GetRender().target_type() != renderMethod.target_type())

                {
                    isWinningDiagonal = false;
                    break;
                }
            }
            if (isWinningDiagonal)
            {
               std::cout<<"WINNING DIAGONAL2"<<std::endl;
               return;
            }
        }
    }
    bool isDraw = true;
    for (int x = 0; x < MapSize; x++)
    {
        for (int y = 0; y < MapSize; y++)
        {
            if (!fields[x][y]->GetIsBusy())
            {
                isDraw = false;
                break;
            }
        }
        if (!isDraw)
            break;
    }
    if (isDraw)
    {
        std::cout<<"DRAW"<<std::endl;
        return;
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
            renderMethod = [r, xPos, yPos]() {r->DrawBlank(xPos, yPos, Field::SIZE);};

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
    genv::gout << genv::refresh;
}


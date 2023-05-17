#include "graphics.hpp"
#include "widgets.hpp"
#include "application.hpp"
#include "button.h"
#include "iostream"


int main()
{
   genv::gout.open(800,600);

   Window w;
   w.event_loop();

   return 0;
}

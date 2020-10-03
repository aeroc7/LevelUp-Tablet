#include "gui_brains.h"

#include <cassert>

void GuiBrains::start(cairo_t * cr) 
{

}

void GuiBrains::loop(cairo_t * cr) 
{
    menu_page.draw_menu(cr);
}

void GuiBrains::stop(cairo_t * cr) 
{
    
}

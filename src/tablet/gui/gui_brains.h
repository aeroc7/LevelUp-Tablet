#ifndef __GUI_BRAINS_H__
#define __GUI_BRAINS_H__

#include <cairo/cairo.h>

#include "pages/pg_menu.h"

#include <memory>

class GuiBrains
{
    public:
        void start(cairo_t * cr);
        void loop(cairo_t * cr);
        void stop(cairo_t * cr);
    private:

        PgMenu menu_page;
};

#endif // __GUI_BRAINS_H__

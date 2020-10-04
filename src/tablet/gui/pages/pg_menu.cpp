#include "pg_menu.h"

#include "../components/cmp_page.h"

CmpPage page_tt("test");

void PgMenu::draw_menu(cairo_t * cr)
{
    page_tt.draw_page(cr);
}

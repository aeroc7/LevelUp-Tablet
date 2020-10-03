#include "cmp_page.h"

#include "../gui_colors.h"
#include "../cairo_helper_func.h"

#include <cmath>

CmpPage::CmpPage(const std::string& title) 
    : page_title(title)
{

}

void CmpPage::draw_page(cairo_t * cr) 
{
    cairo_rounded_rectangle(cr, 20, 100, 670, 450, 59, DK_MODE_CHARCOAL);
}

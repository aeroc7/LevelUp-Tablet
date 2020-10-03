#ifndef __CMP_PAGE_H__
#define __CMP_PAGE_H__

#include <string>

#include <cairo/cairo.h>

class CmpPage
{
    public:
        CmpPage(const std::string& title);
        void draw_page(cairo_t * cr);
    private:

        std::string page_title;
};

#endif // __CMP_PAGE_H__
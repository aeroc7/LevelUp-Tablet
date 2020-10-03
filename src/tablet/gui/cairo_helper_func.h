#ifndef __CAIRO_HELPER_FUNC_H__
#define __CAIRO_HELPER_FUNC_H__

#include <cairo/cairo.h>

#include <cmath>

inline void cairo_rounded_rectangle(cairo_t * cr, double x, double y,
    double width, double height, double corner, double c1, double c2, double c3,
        double c4)
{
    double aspect = 1.0;
    double corner_radius = height / corner;
    double radius = corner_radius / aspect;
    double degrees = M_PI / 180.0;

    cairo_new_sub_path (cr);
    cairo_arc (cr, x + width - radius, y + radius, radius, -90 * degrees, 0 * degrees);
    cairo_arc (cr, x + width - radius, y + height - radius, radius, 0 * degrees, 90 * degrees);
    cairo_arc (cr, x + radius, y + height - radius, radius, 90 * degrees, 180 * degrees);
    cairo_arc (cr, x + radius, y + radius, radius, 180 * degrees, 270 * degrees);
    cairo_close_path (cr);

    cairo_set_source_rgba (cr, c1, c2, c3, c4);
    cairo_fill_preserve (cr);
    cairo_set_source_rgba (cr, c1, c2, c3, c4);
    cairo_set_line_width (cr, 10.0);
    cairo_stroke (cr);
}

#endif // __CAIRO_HELPER_FUNC_H__
#ifndef __GUI_MAIN_H__
#define __GUI_MAIN_H__

#include <cairo_mt_panel.h>

#include <cairo/cairo.h>

#include <tuple>
#include <atomic>
#include <memory>

#include <XPLMDisplay.h>

#include "gui_brains.h"

class GuiMain
{
    public:
        void init();
        void shutdown();
        std::tuple<float, float, float> get_mouse_stats();

    private:
        void cairo_draw_start(cairo_t * cr);
        void cairo_draw_loop(cairo_t * cr);
        void cairo_draw_stop(cairo_t * cr);
        void init_click_window();

        static float xp_fl_cb(float, float, int, void *);

        std::atomic<float> mouse_x { 0 };
        std::atomic<float> mouse_y { 0 };
        std::atomic<float> mouse_click { 0 };

        XPLMWindowID window;

        std::unique_ptr<Cairo_mt_panel> cairo_panel;
        GuiBrains gui_logic;
};

#endif // __GUI_MAIN_H__
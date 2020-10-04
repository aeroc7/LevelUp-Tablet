#ifndef __GUI_MAIN_H__
#define __GUI_MAIN_H__

#if (STANDALONE_BUILD == 1)
#include <cairo_mt_panel.h>
#endif

#include <cairo/cairo.h>

#include <tuple>
#include <atomic>
#include <memory>

#if (STANDALONE_BUILD == 1)
#include <XPLMDisplay.h>
#endif

#include "gui_brains.h"

#if (STANDALONE_BUILD == 0)
#include "standalone-wind.h"
#endif

class GuiMain
{
    public:
        void init();
        void shutdown();
        std::tuple<float, float, float> get_mouse_stats();

    private:
        #if (STANDALONE_BUILD == 1)
        void cairo_draw_start(cairo_t * cr);
        void cairo_draw_loop(cairo_t * cr);
        void cairo_draw_stop(cairo_t * cr);
        void init_click_window();

        static float xp_fl_cb(float, float, int, void *);
        #endif

        std::atomic<float> mouse_x { 0 };
        std::atomic<float> mouse_y { 0 };
        std::atomic<float> mouse_click { 0 };

        #if (STANDALONE_BUILD == 1)
        XPLMWindowID window;

        std::unique_ptr<Cairo_mt_panel> cairo_panel;

        #else

          std::unique_ptr<StandWind> glfw_window;
        #endif

        GuiBrains gui_logic;
};

#endif // __GUI_MAIN_H__

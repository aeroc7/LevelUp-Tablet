#include "gui_main.h"
#include "gui_colors.h"

#include "components/cmp_setup_mouse.h"

#include <logging.h>
#if (STANDALONE_BUILD == 1)
#include <dataref_wrapper.h>

#include <XPLMUtilities.h>
#include <XPLMProcessing.h>
#include <XPLMDataAccess.h>
#include <XPLMDisplay.h>
#endif

#include <cassert>

#if (STANDALONE_BUILD == 1)
constexpr auto loc_x = 1149;
constexpr auto loc_y = 1436;
constexpr auto width = 880;
constexpr auto height = 600;

dataref::DataRef<float> panel_coords_x("sim/graphics/view/click_3d_x_pixels");
dataref::DataRef<float> panel_coords_y("sim/graphics/view/click_3d_y_pixels");
#endif

void GuiMain::init()
{
    //GLenum err = glewInit();

    //if (err != GLEW_OK)
    //    throw std::runtime_error("Failed to initialize glew");

    #if (STANDALONE_BUILD == 1)
    XPLMRegisterFlightLoopCallback(xp_fl_cb, -1.0f, this);

    init_click_window();

    cairo_panel = std::make_unique<Cairo_mt_panel> (loc_x, loc_y, width, height, false,
        false, "LevelUp Tablet");

    /*Way to get around member functions being different.*/
    auto func_t_start = [=](cairo_t * cr) { this->cairo_draw_start(cr); };
    auto func_t_loop = [=](cairo_t * cr) { this->cairo_draw_loop(cr); };
    auto func_t_stop = [=](cairo_t * cr) { this->cairo_draw_stop(cr); };

    cairo_panel->cairo_thread_init(func_t_start, func_t_loop, func_t_stop);

    CmpSetup::init([=](){ return std::tuple<float, float, float>
        (this->mouse_x, this->mouse_y, this->mouse_click);});

    #else

    glfw_window = std::make_unique<StandWind> ();
    glfw_window->init();

    #endif
}

#if (STANDALONE_BUILD == 1)
void GuiMain::cairo_draw_start(cairo_t * cr)
{

}

void GuiMain::cairo_draw_loop(cairo_t * cr)
{
    /*Antialiasing*/
    cairo_set_antialias(cr, CAIRO_ANTIALIAS_GOOD);

    /*Background*/
    cairo_set_source_rgba (cr, LT_MODE_WHITE);
    cairo_paint (cr);

    gui_logic.loop(cr);
}

void GuiMain::cairo_draw_stop(cairo_t * cr)
{

}

float GuiMain::xp_fl_cb(float, float, int, void * ref)
{
    assert(ref != nullptr);
    GuiMain * instance = reinterpret_cast<GuiMain *> (ref);
    instance->mouse_x = panel_coords_x;
    instance->mouse_y = panel_coords_y;
    return -1.0f;
}
#endif

std::tuple<float, float, float> GuiMain::get_mouse_stats()
{
    return std::tuple<float, float, float> (mouse_x, mouse_y, mouse_click);
}

#if (STANDALONE_BUILD == 1)
void GuiMain::init_click_window()
{
  int winLeft, winTop, winRight, winBot;

	XPLMGetScreenBoundsGlobal(&winLeft, &winTop, &winRight, &winBot);

	XPLMCreateWindow_t params;

	params.structSize = sizeof(params);
	params.left = winLeft;
	params.right = winRight;
	params.top = winTop;
	params.bottom = winBot;
	params.visible = 1;
	params.refcon = this;
	params.drawWindowFunc = [](XPLMWindowID, void *){};
	params.handleMouseClickFunc = [](XPLMWindowID, int, int, XPLMMouseStatus stat, void* ref)
        {
            GuiMain * instance = reinterpret_cast<GuiMain *> (ref);
            stat == xplm_MouseDown || stat == xplm_MouseDrag ? instance->mouse_click = 1.0f :
                instance->mouse_click = 0.0f;
                return 0;
        };
	params.handleRightClickFunc = nullptr;
	params.handleMouseWheelFunc = nullptr;
	params.handleKeyFunc = nullptr;
	params.handleCursorFunc = nullptr;
	params.layer = xplm_WindowLayerFlightOverlay;
	params.decorateAsFloatingWindow = xplm_WindowDecorationNone;

	window = XPLMCreateWindowEx(&params);

	XPLMSetWindowPositioningMode(window, xplm_WindowFullScreenOnAllMonitors, -1);
}
#endif

void GuiMain::shutdown()
{
    #if (STANDALONE_BUILD == 1)
    if (cairo_panel) {
        cairo_panel->cairo_thread_destroy();
    }

    XPLMDestroyWindow(window);

    XPLMUnregisterFlightLoopCallback(xp_fl_cb, this);

    #else

    glfw_window->shutdown();

    #endif
}

#include "sys_init.h"

void SysInit::init() 
{
    gui_start_ptr = std::make_unique<GuiMain> ();
    gui_start_ptr->init();
}

void SysInit::shutdown() 
{
    if (gui_start_ptr) {
        gui_start_ptr->shutdown();
    }
}

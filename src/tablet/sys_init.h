#ifndef __SYS_INIT_H__
#define __SYS_INIT_H__

#include "gui/gui_main.h"

#include <memory>

class SysInit
{
    public:
        void init();
        void shutdown();
    private:

        std::unique_ptr<GuiMain> gui_start_ptr;
};

#endif // __SYS_INIT_H__
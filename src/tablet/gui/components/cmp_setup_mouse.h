#ifndef __CMP_SETUP_MOUSE_H__
#define __CMP_SETUP_MOUSE_H__

#include <functional>

class CmpSetup
{
    public:
        static void init(std::function<std::tuple<float, float, float> ()> mouse_func);
        static std::tuple<float, float, float> get_mouse_stats();
    private:
};

#endif // __CMP_SETUP_MOUSE_H__
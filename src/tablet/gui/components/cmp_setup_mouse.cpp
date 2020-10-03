#include "cmp_setup_mouse.h"

#include <cassert>

static std::function<std::tuple<float, float, float> ()> coord_func;

void CmpSetup::init(std::function<std::tuple<float, float, float> ()> mouse_func) 
{
    coord_func = mouse_func;
}

std::tuple<float, float, float> CmpSetup::get_mouse_stats()
{
    assert(coord_func);
    return coord_func();
}

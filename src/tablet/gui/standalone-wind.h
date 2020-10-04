#ifndef __STANDALONE_WIND_H_
#define __STANDALONE_WIND_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class StandWind
{
    public:
        void init();
        void shutdown();
    private:
        void func_loop();
        GLFWwindow * window;
};

#endif

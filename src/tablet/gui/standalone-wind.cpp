#include "standalone-wind.h"

#include <stdexcept>

constexpr auto GL_WIN_WIDTH = 880;
constexpr auto GL_WIN_HEIGHT = 600;
constexpr auto WINDOW_TITLE = "LevelUp Tablet App";

void StandWind::init()
{
    glewInit();
    
    window = glfwCreateWindow(GL_WIN_WIDTH, GL_WIN_HEIGHT, WINDOW_TITLE, nullptr, nullptr);

    if (!window) {
      throw std::runtime_error("Couldn't create GLFW window");
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetWindowUserPointer(window, this);

}

void StandWind::func_loop()
{
  while(!glfwWindowShouldClose(window))
  {

  }
}

void StandWind::shutdown()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

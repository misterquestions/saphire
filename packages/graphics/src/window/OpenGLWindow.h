#pragma once
#include "Window.h"
#include <GLFW/glfw3.h>

namespace saphire
{
    class OpenGLWindow : public Window
    {
    public:
        OpenGLWindow(int width, int height, const char *title) : Window(width, height, title) { create(); };
        ~OpenGLWindow();

        const char *getAPI() override;
        void create() override;
        void update() override;
        void destroy() override;

    private:
        GLFWwindow *m_ptrWindow;

        static void keyboardFunc(GLFWwindow *window, int key, int scancode, int action, int mods);
        static void scrollFunc(GLFWwindow *window, double xoffset, double yoffset);
        
    };
}
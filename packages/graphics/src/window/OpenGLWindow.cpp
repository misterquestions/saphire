#include "OpenGLWindow.h"
#include <GLFW/glfw3.h>
#include <iostream>

using namespace saphire;

const char *OpenGLWindow::getAPI()
{
    return "OpenGL";
}

void OpenGLWindow::create()
{
    // GLFW initialization
    if (!glfwInit())
    {
        std::cout << "Failed to initialize GLFW" << std::endl;
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

    m_ptrWindow = glfwCreateWindow(m_iWidth, m_iHeight, m_strTitle, NULL, NULL);

    if (!m_ptrWindow)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(m_ptrWindow);

    // Glad initialization
    // if (!gladLoadGL())
    // {
    //     std::cout << "Failed to initialize GLAD" << std::endl;
    //     exit(EXIT_FAILURE);
    // }

    glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glDepthFunc(GL_LEQUAL);
	glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);

    glfwSwapInterval(true);
	glfwSetKeyCallback(m_ptrWindow, keyboardFunc);
    glfwSetScrollCallback(m_ptrWindow, scrollFunc);
}

void OpenGLWindow::keyboardFunc(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

void OpenGLWindow::scrollFunc(GLFWwindow *window, double xoffset, double yoffset)
{
}

void OpenGLWindow::update()
{
    glfwSwapBuffers(m_ptrWindow);
    glfwPollEvents();
}

void OpenGLWindow::destroy()
{
    glfwDestroyWindow(m_ptrWindow);
    glfwTerminate();
}
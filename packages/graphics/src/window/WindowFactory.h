#pragma once
#include "OpenGLWindow.h"

namespace saphire
{
    class WindowFactory
    {
    public:
        static Window *CreateWindow(int width, int height, const char *title);
    };
}
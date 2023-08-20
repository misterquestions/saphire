#include "WindowFactory.h"
#include "OpenGLWindow.h"

using namespace saphire;

Window *WindowFactory::CreateWindow(int width, int height, const char *title)
{
    return new OpenGLWindow(width, height, title);
}
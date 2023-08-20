#pragma once

namespace saphire
{
    class Window
    {
    public:
        Window(int width, int height, const char *title) : m_iWidth(width), m_iHeight(height), m_strTitle(title) {}
        ~Window() { destroy(); }

        virtual void create();
        virtual void update();
        virtual void destroy();

        virtual const char *getAPI() = 0;

    protected:
        int m_iWidth;
        int m_iHeight;
        const char *m_strTitle;
    };
}
#pragma once
#include "Window.h"

namespace saphire
{
    class Game
    {
    public:
        Game();
        ~Game();

        void Bootstrap();
        void Tick();
        void Shutdown();

    private:
        Window *m_ptrWindow;
        bool m_bIsRunning;

        void Run();
    };
}
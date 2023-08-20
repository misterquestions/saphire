#include "Game.h"
#include "WindowFactory.h"

using namespace saphire;

Game::Game()
{
}

Game::~Game()
{
}

void Game::Bootstrap()
{
    // Start by creating a window using the WindowFactory
    m_ptrWindow = WindowFactory::CreateWindow(800, 600, "Saphire Engine");

    if (!m_ptrWindow)
    {
        std::cout << "Failed to create window" << std::endl;
        exit(EXIT_FAILURE);
    }

    // TODO: Other initialization stuff

    // Launch the game loop
    Run();
}

void Game::Run()
{
    while (m_bIsRunning)
    {
        Tick();
    }
}

void Game::Tick()
{
    
}

void Game::Shutdown()
{
    
}
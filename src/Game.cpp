#include "Game.h"

Game::Game() 
{
    std::cout << "Initializing..." << std::endl;
            
    _run = true;

    _currentState = new MainState();
    
    Load();
}

Game::~Game()
{
    std::cout << "Ending Game..." << std::endl;
    delete(_currentState);
    delete(Render::Instance());
    delete(Window::Instance());
}

void Game::Load()
{
    if(Window::Instance()->Initialize() == 0)
    {
        _run = false;
        return;
    }

    if(Render::Instance()->Initialize() == 0)
    {
        _run = false;
        return;
    }
    
    if(_currentState->Load() == 0)
    {
        _run = false;
        return;
    }
}

void Game::Run()
{
    std::cout << "Starting Game..." << std::endl;
    
    while(_run)
    {
        _frameTimer.Start();
        HandleEvents();
        _currentState->Update();
        _currentState->Draw();
        Render::Instance()->UpdateDisplay();
        while(_frameTimer.GetTicks() < 1000/FRAMES_PER_SECOND && _run)
        {
        }
    }
}

void Game::HandleEvents()
{
    while(SDL_PollEvent(&_event))
    {
        switch(_event.type)
        {
            case SDL_KEYUP:
            case SDL_KEYDOWN:
                if((_event.key.keysym.sym == SDLK_F4 && _event.key.keysym.mod & KMOD_ALT)
                    || (_event.key.keysym.sym == SDLK_w && _event.key.keysym.mod & KMOD_CTRL))
                {
                        _run = false;
                        break;
                }
                _currentState->HandleEvents(&_event.key);
                break;
            case SDL_VIDEOEXPOSE:
                Draw();
		break;
            case SDL_QUIT:
                _run = false;
                break;
            default:
                break;
        }
    }
}

void Game::Update()
{
}

void Game::Draw() 
{
}

Game *Game::_instance = NULL;
Game *Game::Instance()
{
    if(_instance == NULL)
    {
        _instance = new Game;
    }
    return _instance;
}

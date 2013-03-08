#include "Game.hpp"

#include "ServiceLocator.hpp"
#include "PCRender.hpp"

#include <cassert>
#include "Window.hpp"

#define FRAMES_PER_SECOND 60

/* ---------------------------- *
 * Constructor and Destructor
 * ---------------------------- */

Game::Game()
: _initialized( false ),
  _run ( true ) {}

Game::~Game()
{
    while( !_states.empty() )
    {
        delete( _states.top() );
        _states.pop();
    }

    delete( _render );
    delete( Window::Instance() );
}

/* ---------------------------- *
 * Initialization
 * ---------------------------- */

bool Game::initialize()
{
    if( !_initialized )
    {
        _initialized = true;

        //Create window
        if(Window::Instance()->Initialize() == 0)
        {
            _initialized = false;
        }

        //Select PCRender as the rendering engine
        std::cout << "Loading rendering engine" << std::endl;

        _render = new PCRender();

        ServiceLocator::provide ( _render ); //Make render available on request

        if( !_render->initialize() )
        {
            _initialized = false;
        }

        std::cout << "Game initialized successfully" << std::endl;
    }

    return _initialized;
}

/* ----------------------------------- *
 * Main Game Loop
 * ----------------------------------- */

void Game::run()
{
    std::cout << "Entering main loop" << std::endl;
    while(_run)
    {
        _frameTimer.start();

        _currentState = NULL;

        if(_states.empty())
        {
            std::cout << "No game state" << std::endl;
            _run = false;
            break;
        }

        _currentState = _states.top();

        handleEvents();

        //Update current state
        _currentState->update();

        draw();

        if(_deleteState)
        {
            delete _currentState;
            _deleteState = false;
        }

        //Wait to force constant framerate
        while(_frameTimer.getTicks() < 1000/FRAMES_PER_SECOND && _run)
        {
        }
    }
}

void Game::handleEvents()
{
    //TODO Make this independent of SDL
    while(SDL_PollEvent(&_event))
    {
        switch(_event.type)
        {
            case SDL_KEYUP:
            case SDL_KEYDOWN:

                if((_event.key.keysym.sym == SDLK_F4 && _event.key.keysym.mod & KMOD_ALT)
                || (_event.key.keysym.sym == SDLK_w  && _event.key.keysym.mod & KMOD_CTRL))
                {
                        _run = false;
                        break;
                }
                if( _currentState )
                {
                    _currentState->handleEvents(&_event.key);
                }

                break;
            case SDL_VIDEOEXPOSE:
                draw();
                break;
            case SDL_QUIT:
                _run = false;
                break;
            default:
                break;
        }
    }
}

void Game::draw()
{
    //Draw current state
    if( _currentState )
        _currentState->draw(_render);

    //Update the screen
    _render->flipDisplay();

}

/* ----------------------------------- *
 * State management
 * ----------------------------------- */

bool Game::pushState( GameState* state )
{
    if( state->initialize() )
    {
        std::cout << "Loaded state successfully" << std::endl;
        _states.push( state );

        return true;
    }

    std::cout << "Not pushing state" << std::endl;

    return false;
}

void Game::popState()
{
    _deleteState = true;
    _states.pop();
}

/* ----------------------------------- *
 * Singleton stuff
 * TODO Make this not a singleton
 * ----------------------------------- */

Game *Game::_instance = NULL;
Game *Game::Instance()
{
    if(_instance == NULL)
    {
        _instance = new Game;
    }
    return _instance;
}

/* --------------------------- *
 * Update and draw functions
 * May be useful later?
 * --------------------------- */

void Game::update()
{
}

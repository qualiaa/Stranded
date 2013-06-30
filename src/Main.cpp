/*
 * File:   Main.cpp
 * Author: jamie
 *
 * The motherfucking bird game, motherfuckers.
 *
 * Created on 17 December 2011, 04:26
 */

#include "Engine/System/Game.hpp"
#include "MainState.hpp"

int main()
{
    if(tank::Game::initialize({640, 640}))
    {
        tank::Game::makeState<MainState>();
        tank::Game::run();
        tank::Game::close();
    }

    return 0;
}

/*
 * File:   Main.cpp
 * Author: jamie
 *
 * The motherfucking bird game, motherfuckers.
 *
 * Created on 17 December 2011, 04:26
 */

#include <iostream>
#include "Engine/System/Game.hpp"
#include "MainState.hpp"

int main()
{
    if( Game::Instance()->initialize() )
    {
        Game::Instance()->addState(new MainState()); 
        Game::Instance()->run();
    }

    delete(Game::Instance());

    return 0;
}

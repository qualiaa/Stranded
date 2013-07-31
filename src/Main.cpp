/*
 * File:   Main.cpp
 * Author: jamie
 *
 * The motherfucking bird game, motherfuckers.
 *
 * Created on 17 December 2011, 04:26
 */

#include <Tank/System/Game.hpp>
#include "MainState.hpp"
#include <Tank/Audio/Music.hpp>

int main()
{
    tank::Music music {"res/music.ogg"};
    music.play();
    if(tank::Game::initialize({640, 640}))
    {
        tank::Game::makeState<MainState>();
        tank::Game::run();
    }

    return 0;
}

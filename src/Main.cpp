/* 
 * File:   Main.cpp
 * Author: jamie
 *
 * The motherfucking bird game, motherfuckers.
 * 
 * Created on 17 December 2011, 04:26
 */

#include <iostream>
#include "Game.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    Game::Instance()->Run();
    delete(Game::Instance());
    
    return 0;
}
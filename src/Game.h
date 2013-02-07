/* 
 * File:   Game.h
 * Author: jamie
 *
 * Created on 17 December 2011, 05:01
 */

#ifndef GAME_H
#define	GAME_H

#include <iostream>
#include <SDL/SDL.h>
#include "Timer.h"
#include "Window.h"
#include "Render.h"
#include "MainState.h"

class Game
{
public:    
    void Run();
    
    static Game* Instance();
    ~Game();
private:
    bool _run;
    SDL_Event _event;
    GameState* _currentState;
    Timer _frameTimer;
    
    void Load();

    void HandleEvents();
    void Update();
    void Draw();
    
    static Game* _instance;
    Game();
};


#endif	/* GAME_H */


#pragma once
#ifndef GAMESTATE_H
#define	GAMESTATE_H

#include <vector>
#include <SDL/SDL_events.h>
#include "IRender.hpp"

class Entity;
class Game;

class GameState
{
public:    
    void addEntity   (Entity*const ent);
    void removeEntity(Entity*const ent);
    
    virtual bool initialize() = 0;
    virtual void handleEvents(SDL_KeyboardEvent *const) = 0;
    virtual void update();
    virtual void draw  ( IRender *const );
    
    GameState();
    virtual ~GameState();
protected: 
    std::vector<Entity*> _entities;
    bool _initialized;
}; 
#endif 

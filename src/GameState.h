/* 
 * File:   World.h
 * Author: jamie
 *
 * Created on 19 December 2011, 01:32
 */

#ifndef WORLD_H
#define	WORLD_H

#include <vector>
#include "Entity.h"

class Entity;

class GameState
{
public:    
    virtual void HandleEvents(SDL_KeyboardEvent*) = 0;
    virtual void Update();
    virtual void Draw();
    
    void DisplayText(float x, float y, char* text);
    void AddEntity(Entity *ent);
    void RemoveEntity(Entity *ent);
    
    virtual int Load() = 0;
    
    GameState();
    virtual ~GameState();
protected:
    std::vector<Entity*> _entities;
    bool _loaded;
};


#endif	/* WORLD_H */


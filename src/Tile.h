/* 
 * File:   Tile.h
 * Author: jamie
 *
 * Created on 18 December 2011, 21:13
 */

#ifndef TILE_H
#define	TILE_H

#include "Entity.h"
#include "Enums.h"

class Tile : public Entity
{
public:
    virtual void HandleInput(SDL_KeyboardEvent*) {}
    virtual void Update();
    
    virtual void IsInside(Entity*) {};
    
    Tile(float x, float y, GameState* state,EntityType, Rotation);
    ~Tile() {}
private:
    Vector _tilePos;
    
};

#endif	/* TILE_H */
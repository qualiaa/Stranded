#pragma once
#ifndef ROOM_H
#define	ROOM_H

#include <vector>
#include "Engine/Utility/Vector.hpp"
#include "Engine/System/State.hpp"
#include "Tile.hpp"

class Player;

class Room
{
public:
    bool load(State *const state);

    void handleInput(SDL_KeyboardEvent *const);
    void update();
    void draw(IRender *const render);

    std::vector<Tile*>&   GetTiles()    { return _tiles; }
    std::vector<Entity*>& GetEntities() { return _entities; }

    Room(Vectori const& coords);

    ~Room();
private:
    Vectori  _coords;

    std::vector<Tile*>   _tiles;
    std::vector<Entity*> _entities;
}; 
#endif

#pragma once
#ifndef ROOM_H
#define	ROOM_H

#include <vector>
#include "Enums.hpp"
#include "Engine/Vector.hpp"
#include "Engine/GameState.hpp"
#include "Tile.hpp"

class Player;

class Room
{
public:
    bool load( GameState* state );

    void handleInput( SDL_KeyboardEvent *const );
    void update();
    void draw(IRender *const render);

    std::vector<Tile*>   GetTiles()    { return _tiles; }
    std::vector<Entity*> GetEntities() { return _entities; }

    Room( Vector const& coords, Entity *const player );

    ~Room();
private:
    Vector _coords;
    bool _currentRoom;

    std::vector<Tile*> _tiles;
    std::vector<Entity*> _entities;
}; 
#endif

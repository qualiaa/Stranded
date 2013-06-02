#pragma once
#ifndef ROOM_H
#define	ROOM_H

#include <vector>
#include "Engine/Utility/Vector.hpp"
#include "Engine/System/GameState.hpp"
#include "Tile.hpp"

class Player;

class Room
{
public:
    bool load(GameState *const state);

    void handleInput(SDL_KeyboardEvent *const);
    void update();
    void draw(IRender *const render);

    std::vector<Tile*>   GetTiles()    { return _tiles; }
    std::vector<Entity*> GetEntities() { return _entities; }

    Room(Vector const& coords, Player *const);

    ~Room();
private:
    Vector  _coords;
    bool    _currentRoom;
    Player* _player;

    std::vector<Tile*>   _tiles;
    std::vector<Entity*> _entities;
}; 
#endif

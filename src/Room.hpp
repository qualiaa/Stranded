#pragma once
#ifndef ROOM_H
#define	ROOM_H

#include <vector>
#include <memory>
#include "Engine/Utility/Vector.hpp"
#include "Engine/System/State.hpp"
#include "Player.hpp"
#include "Tile.hpp"

class Player;

class Room : public State
{
public:
    //bool load(State *const state);

    //void handleInput(SDL_KeyboardEvent *const);
    //void update();
    void draw(IRender *const render); 

    static const int ROOM_SIZE = 10;

    //std::vector<std::unique_ptr<Tile>>&   GetTiles()    { return tiles_; }
    //std::vector<std::unique_ptr<Entity>>& GetEntities() { return entities_; }

    Room(Vectori const& coords);

    ~Room();
private:
    Vectori  coords_;
};
#endif

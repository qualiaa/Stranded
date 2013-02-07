/* 
 * File:   Room.h
 * Author: jamie
 *
 * Created on 19 December 2011, 00:59
 */

#ifndef ROOM_H
#define	ROOM_H

#include <vector>
#include <deque>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include "Enums.h"
#include "Vector.h"
#include "Player.h"
#include "Tile.h"
#include "Object.h"
#include "LargeTreeObject.h"
#include "SmallTreeObject.h"
#include "PalmTreeObject.h"
#include "BambooObject.h"
#include "LargeRockObject.h"
#include "SmallRockObject.h"

class Player;

class Room
{
public:
    bool Load(GameState* state);

    void HandleInput(SDL_KeyboardEvent*);
    void Update();
    void Draw();

    std::vector<Tile*> GetTiles() { return _tiles; }
    std::vector<Entity*> GetEntities() { return _entities; }

    Room(Vector &vect,Entity* player);

    ~Room();
private:
    Vector _coords;
    bool _currentRoom;

    std::vector<Tile*> _tiles;
    std::vector<Entity*> _entities;
};


#endif	/* ROOM_H */
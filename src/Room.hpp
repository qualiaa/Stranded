#ifndef ROOM_H
#define	ROOM_H

#include <vector>
#include <memory>
#include <Tank/Utility/Vector.hpp>
#include <Tank/System/World.hpp>
#include "Player.hpp"
#include "Tile.hpp"

class Player;

class Room : public tank::World
{
public:
    static const int ROOM_SIZE = 10;

    Room(tank::Vectori coords);

    ~Room();
};
#endif

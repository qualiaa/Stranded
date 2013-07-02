#ifndef ROOM_H
#define	ROOM_H

#include <vector>
#include <memory>
#include "Engine/Utility/Vector.hpp"
#include "Engine/System/State.hpp"
#include "Player.hpp"
#include "Tile.hpp"

class Player;

class Room : public tank::State
{
public:
    static const int ROOM_SIZE = 10;

    Room(tank::Vectori coords);

    ~Room();
};
#endif

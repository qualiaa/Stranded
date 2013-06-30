#ifndef TILE_H
#define	TILE_H

#include "Engine/System/Entity.hpp"

class Tile : public tank::Entity
{
public:
    Tile (tank::Vectorf pos, int tileID, unsigned int rotation);

    static const int TILE_SIZE;
};
#endif

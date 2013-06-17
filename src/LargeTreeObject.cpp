#include "LargeTreeObject.hpp"

#include "Tile.hpp"

LargeTreeObject::LargeTreeObject(Vectorf const& pos)
:Object( pos, "largetree" )
{
    const int hbHeight = 9;
    setHitbox({ 18, Tile::TILE_SIZE * 2 - 8 - hbHeight, 28, hbHeight});
    setSolid(true);
}

LargeTreeObject::~LargeTreeObject() {
}


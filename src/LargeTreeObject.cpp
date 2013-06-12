#include "LargeTreeObject.hpp"

#include "Tile.hpp"

LargeTreeObject::LargeTreeObject(Vectorf const& pos)
:Object( pos, "largetree" )
{
    hitbox_ = { 18, hitbox_.y = Tile::TILE_SIZE * 2 - 8 - hitbox_.h, 28, 9 };
    solid_ = true;
}

LargeTreeObject::~LargeTreeObject() {
}


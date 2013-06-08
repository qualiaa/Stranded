#include "LargeTreeObject.hpp"

#include "Tile.hpp"

LargeTreeObject::LargeTreeObject(Vectorf const& pos)
:Object( pos, "largetree" )
{
    _hitbox = { 18, _hitbox.y = Tile::TILE_SIZE * 2 - 8 - _hitbox.h, 28, 9 };
    _solid = true;
}

LargeTreeObject::~LargeTreeObject() {
}


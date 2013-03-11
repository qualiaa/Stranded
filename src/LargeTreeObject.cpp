#include "LargeTreeObject.hpp"

#include "Tile.hpp"

LargeTreeObject::LargeTreeObject(Vector const& pos )
:Object( pos, "largetree" )
{
    _hitBox.h = 9;
    _hitBox.y += Tile::TILE_SIZE * 2 - 8 - _hitBox.h;
    _hitBox.w = 28;
    _hitBox.x += 18;
    _solid = true;
}

LargeTreeObject::~LargeTreeObject() {
}


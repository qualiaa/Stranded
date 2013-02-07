#include "Tile.h"

Tile::Tile(float x, float y, GameState* state, EntityType entType, Rotation rot):Entity(x,y, state, entType, rot)
{
    _tilePos = _pos;
    _pos *= 64;
    _hitBox.x = _pos.x;
    _hitBox.y = _pos.y;
}

void Tile::Update()
{
}
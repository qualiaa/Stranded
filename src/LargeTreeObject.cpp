#include "LargeTreeObject.hpp"

#include "Engine/Graphics/Image.hpp"
#include "MainState.hpp"
#include "Tile.hpp"

#include "Engine/System/Game.hpp"

LargeTreeObject::LargeTreeObject(tank::Vectorf pos)
    : Object(pos)
{
    makeGraphic<tank::Image>(MainState::largetree);
    const int hbHeight = 9;
    setHitbox({ 18, Tile::TILE_SIZE * 2 - 8 - hbHeight, 28, hbHeight});

    setSolid(true);
}

#include "LargeTreeObject.hpp"

#include <Tank/Graphics/Image.hpp>
#include "MainState.hpp"
#include "Tile.hpp"

#include <Tank/System/Game.hpp>

LargeTreeObject::LargeTreeObject(tank::Vectorf pos)
    : Object(pos)
{
    makeGraphic<tank::Image>(MainState::largetree);
    const int hbHeight = 9;
    setHitbox({ 18, static_cast<double>(Tile::TILE_SIZE) * 2 - 8 - hbHeight, 28, hbHeight});

    setType("solid");
}

#include "SmallTreeObject.hpp"

#include <Tank/Graphics/Image.hpp>
#include "MainWorld.hpp"
#include "Tile.hpp"

SmallTreeObject::SmallTreeObject(tank::Vectorf pos)
    : Object(pos)
{
    makeGraphic(MainWorld::smallrock);
    tank::Rectd hb = { 18, static_cast<double>(Tile::TILE_SIZE) - 8, 28, 9 };
    hb.y -= hb.h;

    setHitbox(hb);
    setType("solid");
}

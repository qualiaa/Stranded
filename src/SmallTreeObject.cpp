#include "SmallTreeObject.hpp"

#include "Engine/Graphics/Image.hpp"
#include "MainState.hpp"
#include "Tile.hpp"

SmallTreeObject::SmallTreeObject(tank::Vectorf pos)
    : Object(pos)
{
    makeGraphic<tank::Image>(MainState::smallrock);
    tank::Rectd hb = { 18, static_cast<double>(Tile::TILE_SIZE) - 8, 28, 9 };
    hb.y -= hb.h;

    setHitbox(hb);
    setSolid(true);
}

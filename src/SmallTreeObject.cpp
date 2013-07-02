#include "SmallTreeObject.hpp"

#include "Engine/Graphics/Image.hpp"
#include "MainState.hpp"
#include "Tile.hpp"

SmallTreeObject::SmallTreeObject(tank::Vectorf pos)
    : Object(pos)
{
    setGraphic<tank::Image>(MainState::smallrock);
    tank::Rect hb = { 18, Tile::TILE_SIZE - 8, 28, 9 };
    hb.y -= hb.h;

    setHitbox(hb);
    setSolid(true);
}

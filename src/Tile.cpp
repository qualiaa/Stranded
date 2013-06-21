#include "Tile.hpp"

#include "Engine/System/ServiceLocator.hpp"

const int Tile::TILE_SIZE = 64;

Tile::Tile(Vectorf const& pos, int tileID, unsigned int rotation)
    :Entity(pos * static_cast<float>(TILE_SIZE))
{
    setHitbox({ 0, 0, TILE_SIZE, TILE_SIZE });
    setType("tile");

    std::string texture = "";

    switch( tileID )
    {
        case 100:
            texture = "grass";
            break;
        case 200:
            texture = "woodland";
            break;
        case 300:
            texture = "sand";
            break;
        case 400:
            setSolid(true);
            texture = "sandwater";
            break;
        case 500:
            setSolid(true);
            texture = "water";
            break;
        default:
            break;
    }

    setTexture(tank::ServiceLocator::getRender()->getTexture(texture.c_str()));

    tile_ = tank::Animation(getTexture(), { TILE_SIZE, TILE_SIZE });
    tile_.add("tile", { rotation }, 0);
    tile_.select("tile", false );
}

void Tile::draw(tank::IRender *const render)
{
    tile_.draw(render, getPos());
}

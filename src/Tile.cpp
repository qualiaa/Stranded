#include "Tile.hpp"

#include "Engine/System/ServiceLocator.hpp"

const int Tile::TILE_SIZE = 64;

Tile::Tile(Vectorf const& pos, int tileID, unsigned int rotation)
    :Entity(pos * static_cast<float>(TILE_SIZE))
{
    hitbox_ = { 0, 0, TILE_SIZE, TILE_SIZE };
    type_ = "tile";

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
            solid_ = true;
            texture = "sandwater";
            break;
        case 500:
            solid_ = true;
            texture = "water";
            break;
        default:
            break;
    }

    texture_ = ServiceLocator::getRender()->getTexture(texture.c_str());

    tile_ = Animation(texture_, { TILE_SIZE, TILE_SIZE });
    tile_.add("tile", { rotation }, 0);
    tile_.select("tile", false );
}

void Tile::draw(IRender *const render)
{
    tile_.draw(render, pos_);
}

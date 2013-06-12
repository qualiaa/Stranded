#include "Tile.hpp"

#include "Engine/System/ServiceLocator.hpp"

const int Tile::TILE_SIZE = 64;

Tile::Tile(Vectorf const& pos, int tileID, unsigned int rotation)
    :Entity(pos * static_cast<float>(TILE_SIZE))
{
    _hitbox = { 0, 0, TILE_SIZE, TILE_SIZE };
    _type = "tile";

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
            _solid = true;
            texture = "sandwater";
            break;
        case 500:
            _solid = true;
            texture = "water";
            break;
        default:
            break;
    }

    _texture = ServiceLocator::getRender()->getTexture(texture.c_str());

    _tile = Animation(_texture, { TILE_SIZE, TILE_SIZE });
    _tile.add("tile", { rotation }, 0);
    _tile.select("tile", false );
}

void Tile::draw(IRender *const render)
{
    _tile.draw(render, _pos);
}

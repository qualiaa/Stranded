#include "Tile.hpp"

#include <iostream>
#include "Engine/System/ServiceLocator.hpp"

const int Tile::TILE_SIZE = 64;

Tile::Tile(Vector const& pos, int tileID, unsigned int rotation)
:Entity  (pos * TILE_SIZE                           ),
 _tilePos(pos                                       )
{
    _hitBox.x = _pos.x;
    _hitBox.y = _pos.y;
    _hitBox.w = _hitBox.h = TILE_SIZE;

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

    _texture = ServiceLocator::getRender()->getTexture( texture.c_str() );
    _tile = Animation( _texture, { TILE_SIZE, TILE_SIZE} );
    _tile.add( "tile", { rotation }, 0 );
    _tile.play( "tile", false );
}

void Tile::draw(IRender *const render)
{
    _tile.draw(render, _pos);
}

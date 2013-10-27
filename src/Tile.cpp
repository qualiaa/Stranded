#include "Tile.hpp"

#include <stdexcept>
#include <Tank/Graphics/Image.hpp>
#include <Tank/System/Game.hpp>
#include "MainState.hpp"

const int Tile::TILE_SIZE = 64;

Tile::Tile(tank::Vectorf pos, int tileID, unsigned int rotation)
    : tank::Entity(pos * static_cast<float>(TILE_SIZE))
{
    setHitbox({ 0, 0, TILE_SIZE, TILE_SIZE });
    addType("tile");
    setLayer(-100);

    tank::Image* image;

    switch( tileID )
    {
        case 100:
            image = &MainState::grass;
            break;
        /*case 200:
            //texture = "woodland";
            break;*/
        case 300:
            image = &MainState::sand;
            break;
        case 400:
            image = &MainState::sandwater;
            addType("solid");
            break;
        case 500:
            image = &MainState::water;
            addType("solid");
            break;
        default:
            throw std::runtime_error("Unknown tileID");
            break;
    }

    makeGraphic <tank::Image>(*image);
    getGraphic()->setClip({rotation * 64, 0, 64 ,64});
}

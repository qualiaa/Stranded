#ifndef TILE_H
#define	TILE_H

#include "Engine/System/Entity.hpp"
#include "Engine/Graphics/Animation.hpp"

class Tile : public tank::Entity
{
public:
    virtual void draw(tank::IRender *const);

    Tile (tank::Vectorf const& pos, int tileID, unsigned int rotation);

    static const int TILE_SIZE;
private:
    tank::Animation tile_;
};
#endif

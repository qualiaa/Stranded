#ifndef TILE_H
#define	TILE_H

#include "Engine/System/Entity.hpp"
#include "Engine/Graphics/Animation.hpp"

class Tile : public Entity
{
public:
    virtual void draw(IRender *const);
    
    Tile (Vectorf const& pos, int tileID, unsigned int rotation);

    static const int TILE_SIZE;
private:
    Animation _tile;
}; 
#endif

#ifndef TILE_H
#define	TILE_H

#include "Engine/System/Entity.hpp"
#include "Engine/Graphics/Animation.hpp"

class Tile : public Entity
{
public:
    virtual void update() {}
    virtual void draw(IRender *const);
    
    virtual void isInside(Entity*) {};
    
    Tile (Vectorf const& pos, int tileID, unsigned int rotation);

    static const int TILE_SIZE;
private:
    Animation _tile;
    Vectorf    _tilePos; 
}; 
#endif

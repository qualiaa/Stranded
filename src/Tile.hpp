#ifndef TILE_H
#define	TILE_H

#include "Engine/Entity.hpp"
#include "Engine/Animation.hpp"

class Tile : public Entity
{
public:
    virtual void update() {}
    virtual void draw(IRender *const);
    
    virtual void isInside(Entity*) {};
    
    Tile (Vector const& pos, int tileID, unsigned int rotation);

    static const int TILE_SIZE;
private:
    Animation _tile;
    Vector    _tilePos; 
}; 
#endif

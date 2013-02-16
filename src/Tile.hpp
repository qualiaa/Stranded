/* 
 * File:   Tile.hpp
 * Author: jamie
 *
 * Created on 18 December 2011, 21:13
 */

#ifndef TILE_H
#define	TILE_H

#include "Engine/Entity.hpp"
#include "Engine/Animation.hpp"

class Animation;

class Tile : public Entity
{
public:
    virtual void update() {}
    virtual void draw(IRender *const);
    
    virtual void isInside(Entity*) {};
    
    Tile( Vector const& pos, int tileID, int rotation );
    ~Tile() {}

    static const int TILE_SIZE;
private:
    Animation _tile;
    Vector    _tilePos;
    
};

#endif	/* TILE_H */

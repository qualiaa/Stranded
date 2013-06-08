/* 
 * File:   PalmTreeObject.cpp
 * Author: jamie
 * 
 * Created on 06 January 2012, 01:26
 */

#include "PalmTreeObject.hpp"
#include "Tile.hpp"

PalmTreeObject::PalmTreeObject( Vectorf const& pos )
:Object( pos, "palmtree" )
{
    _hitbox = { 30, Tile::TILE_SIZE * 2 - 4, 16, 6 };
    _hitbox.y -= _hitbox.h;
    _solid = true;
}

PalmTreeObject::~PalmTreeObject() {
} 

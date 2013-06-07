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
    _hitBox.h = 6;
    _hitBox.y += Tile::TILE_SIZE * 2 - 4 - _hitBox.h;
    _hitBox.w = 16;
    _hitBox.x += 30;
    _solid = true;
}

PalmTreeObject::~PalmTreeObject() {
} 

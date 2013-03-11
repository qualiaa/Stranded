/* 
 * File:   SmallTreeObject.cpp
 * Author: jamie
 * 
 * Created on 05 January 2012, 23:28
 */

#include "SmallTreeObject.hpp"
#include "Tile.hpp"

SmallTreeObject::SmallTreeObject( Vector const& pos )
:Object( pos, "smalltree" )
{
    _hitBox.h = 9;
    _hitBox.y += Tile::TILE_SIZE - 8 - _hitBox.h;
    _hitBox.w = 28;
    _hitBox.x += 18;
    _solid = true;
}

SmallTreeObject::~SmallTreeObject() {
} 

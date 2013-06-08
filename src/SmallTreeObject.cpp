/* 
 * File:   SmallTreeObject.cpp
 * Author: jamie
 * 
 * Created on 05 January 2012, 23:28
 */

#include "SmallTreeObject.hpp"
#include "Tile.hpp"

SmallTreeObject::SmallTreeObject( Vectorf const& pos )
:Object( pos, "smalltree" )
{
    _hitbox = { 18, Tile::TILE_SIZE - 8, 28, 9 };
    _hitbox.y -= _hitbox.h;
    _solid = true;
}

SmallTreeObject::~SmallTreeObject() {
} 

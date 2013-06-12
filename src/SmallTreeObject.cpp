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
    hitbox_ = { 18, Tile::TILE_SIZE - 8, 28, 9 };
    hitbox_.y -= hitbox_.h;
    solid_ = true;
}

SmallTreeObject::~SmallTreeObject() {
}

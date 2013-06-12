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
    hitbox_ = { 30, Tile::TILE_SIZE * 2 - 4, 16, 6 };
    hitbox_.y -= hitbox_.h;
    solid_ = true;
}

PalmTreeObject::~PalmTreeObject() {
}

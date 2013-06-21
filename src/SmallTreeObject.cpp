/*
 * File:   SmallTreeObject.cpp
 * Author: jamie
 *
 * Created on 05 January 2012, 23:28
 */

#include "SmallTreeObject.hpp"
#include "Tile.hpp"

SmallTreeObject::SmallTreeObject(tank::Vectorf const& pos )
:Object( pos, "smalltree" )
{
    tank::Rect hb = { 18, Tile::TILE_SIZE - 8, 28, 9 };
    hb.y -= hb.h;

    setHitbox(hb);
    setSolid(true);
}

SmallTreeObject::~SmallTreeObject() {
}

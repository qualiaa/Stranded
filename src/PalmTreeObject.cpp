/*
 * File:   PalmTreeObject.cpp
 * Author: jamie
 *
 * Created on 06 January 2012, 01:26
 */

#include "PalmTreeObject.hpp"
#include "Tile.hpp"

PalmTreeObject::PalmTreeObject(tank::Vectorf const& pos )
:Object( pos, "palmtree" )
{
    tank::Rect hb = { 30, Tile::TILE_SIZE * 2 - 4, 16, 6 };
    hb.y -= hb.h;
    setHitbox(hb);

    setSolid(true);
}

PalmTreeObject::~PalmTreeObject() {
}

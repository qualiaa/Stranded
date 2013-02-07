/* 
 * File:   SmallTreeObject.cpp
 * Author: jamie
 * 
 * Created on 05 January 2012, 23:28
 */

#include "SmallTreeObject.h"

SmallTreeObject::SmallTreeObject(float x, float y,GameState* state):Object(x,y,state,ENT_TREE_SMALL,ROT_NONE)
{
    _impediment = true;
    _hitBox.h = 9;
    _hitBox.y += TILE_SIZE - 8 - _hitBox.h;
    _hitBox.w = 28;
    _hitBox.x += 18;
    _impediment = true;
}

SmallTreeObject::~SmallTreeObject() {
}


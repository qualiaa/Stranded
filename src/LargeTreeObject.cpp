/* 
 * File:   LargeTreeObject.cpp
 * Author: jamie
 * 
 * Created on 05 January 2012, 23:35
 */

#include "LargeTreeObject.h"

LargeTreeObject::LargeTreeObject(float x, float y,GameState* state): Object(x,y,state,ENT_TREE_LARGE,ROT_NONE)
{
    _hitBox.h = 9;
    _hitBox.y += TILE_SIZE * 2 - 8 - _hitBox.h;
    _hitBox.w = 28;
    _hitBox.x += 18;
    _texHeight = 2;
    _impediment = true;
}

LargeTreeObject::~LargeTreeObject() {
}


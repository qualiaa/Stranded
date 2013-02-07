/* 
 * File:   PalmTreeObject.cpp
 * Author: jamie
 * 
 * Created on 06 January 2012, 01:26
 */

#include "PalmTreeObject.h"

PalmTreeObject::PalmTreeObject(float x, float y,GameState* state):Object(x,y,state,ENT_TREE_PALM,ROT_NONE)
{
    _hitBox.h = 6;
    _hitBox.y += TILE_SIZE * 2 - 4 - _hitBox.h;
    _hitBox.w = 16;
    _hitBox.x += 30;
    _texHeight = 2;
    _impediment = true;
}

PalmTreeObject::~PalmTreeObject() {
} 

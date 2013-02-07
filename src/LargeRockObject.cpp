/* 
 * File:   LargeRockObject.cpp
 * Author: jamie
 * 
 * Created on 11 January 2012, 14:52
 */

#include "LargeRockObject.h"

LargeRockObject::LargeRockObject(float x, float y, GameState* state):Object(x,y,state,ENT_ROCK_LARGE,ROT_NONE)
{
    _hitBox.h = 32;
    _hitBox.y += 12;
    _hitBox.w = 42;
    _hitBox.x += 12;
    _impediment = true;
}

LargeRockObject::~LargeRockObject() {
}


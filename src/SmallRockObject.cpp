/* 
 * File:   SmallRockObject.cpp
 * Author: jamie
 * 
 * Created on 11 January 2012, 15:21
 */

#include "SmallRockObject.h"

SmallRockObject::SmallRockObject(float x, float y,GameState* state):Object(x,y,state,ENT_ROCK_SMALL,ROT_NONE)
{
    _hitBox.h = 18;
    _hitBox.y += 30;
    _hitBox.w = 22;
    _hitBox.x += 12;
    _impediment = true;
}

SmallRockObject::~SmallRockObject()
{
}


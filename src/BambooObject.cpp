/* 
 * File:   BambooObject.cpp
 * Author: jamie
 * 
 * Created on 06 January 2012, 01:35
 */

#include "BambooObject.h"

BambooObject::BambooObject(float x, float y, GameState* state):Object(x,y,state,ENT_BAMBOO,ROT_NONE)
{
    _hitBox.x += 14;
    _hitBox.w = 24;
    _hitBox.y += 42;
    _hitBox.h = 8;
    _impediment = true;
}

BambooObject::~BambooObject()
{
    
}

void BambooObject::IsInside(Entity* ent)
{
    switch(ent->GetEntType())
    {
        case ENT_PLAYER:
            _rotation = ROT_UP;
            _impediment = false;
            break;
        default:
            break;
    }
}

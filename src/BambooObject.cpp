/* 
 * File:   BambooObject.cpp
 * Author: jamie
 * 
 * Created on 06 January 2012, 01:35
 */

#include "BambooObject.hpp"

BambooObject::BambooObject(Vector const& pos):Entity( pos )
{
    _hitBox.x += 14;
    _hitBox.w = 24;
    _hitBox.y += 42;
    _hitBox.h = 8;
    _solid = true;
}

BambooObject::~BambooObject()
{
    
}

void BambooObject::isInside(Entity* ent)
{
    /*switch(ent->GetEntType())
    {
        case ENT_PLAYER:
            _rotation = ROT_UP;
            _impediment = false;
            break;
        default:
            break;
    }*/
}

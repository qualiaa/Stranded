/* 
 * File:   SmallRockObject.cpp
 * Author: jamie
 * 
 * Created on 11 January 2012, 15:21
 */

#include "SmallRockObject.hpp"

SmallRockObject::SmallRockObject(Vectorf const& pos )
:Object( pos, "smallrock" )
{
    _hitBox.h = 18;
    _hitBox.y += 30;
    _hitBox.w = 22;
    _hitBox.x += 12;
    _solid = true;
}

SmallRockObject::~SmallRockObject()
{
}


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
    _hitbox = { 12, 30, 22, 18 };
    _solid = true;
}

SmallRockObject::~SmallRockObject()
{
}


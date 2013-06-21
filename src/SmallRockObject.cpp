/*
 * File:   SmallRockObject.cpp
 * Author: jamie
 *
 * Created on 11 January 2012, 15:21
 */

#include "SmallRockObject.hpp"

SmallRockObject::SmallRockObject(tank::Vectorf const& pos )
:Object( pos, "smallrock" )
{
    setHitbox({ 12, 30, 22, 18 });
    setSolid(true);
}

SmallRockObject::~SmallRockObject()
{
}


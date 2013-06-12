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
    hitbox_ = { 12, 30, 22, 18 };
    solid_ = true;
}

SmallRockObject::~SmallRockObject()
{
}


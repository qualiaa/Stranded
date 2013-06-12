/* 
 * File:   LargeRockObject.cpp
 * Author: jamie
 * 
 * Created on 11 January 2012, 14:52
 */

#include "LargeRockObject.hpp"

LargeRockObject::LargeRockObject(Vectorf const& pos)
    :Object(pos, "largerock")
{
    hitbox_ = { 12, 12, 42, 32 };
    solid_ = true;
}

LargeRockObject::~LargeRockObject() {
}


/* 
 * File:   LargeRockObject.cpp
 * Author: jamie
 * 
 * Created on 11 January 2012, 14:52
 */

#include "LargeRockObject.hpp"

LargeRockObject::LargeRockObject(tank::Vectorf const& pos)
    :Object(pos, "largerock")
{
    setHitbox({ 12, 12, 42, 32 });
    setSolid(true);
}

LargeRockObject::~LargeRockObject() {
}


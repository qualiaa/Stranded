/* 
 * File:   LargeRockObject.cpp
 * Author: jamie
 * 
 * Created on 11 January 2012, 14:52
 */

#include "LargeRockObject.hpp"

LargeRockObject::LargeRockObject( Vector const& pos )
:Object( pos, "largerock" )
{
    _hitBox.h = 32;
    _hitBox.y += 12;
    _hitBox.w = 42;
    _hitBox.x += 12;
    _solid = true;
}

LargeRockObject::~LargeRockObject() {
}


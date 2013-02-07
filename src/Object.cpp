/* 
 * File:   Object.cpp
 * Author: jamie
 * 
 * Created on 22 December 2011, 05:09
 */

#include "Object.h"

Object::Object(float x, float y, GameState* state, EntityType entType, Rotation rot):Entity(x,y,state,entType,rot)
{
}

Object::~Object() 
{
}


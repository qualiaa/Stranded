/* 
 * File:   Mover.cpp
 * Author: jamie
 * 
 * Created on 17 December 2011, 18:12
 */

#include "Mover.h"

Mover::Mover(float x, float y, GameState* state, EntityType entType, Rotation rot):Entity(x,y,state,entType, rot)
{
    _vel = Vector(0,0);
    _speed = 2;
}

Mover::~Mover() {}

void Mover::Update()
{    
    if(_vel.x != 0)
    {
        _movingX = true;
    }
    else
    {
        _movingX = false;
    }
    if(_vel.y != 0)
    {
        _movingY = true;
    }
    else
    {
        _movingY = false;
    }
    
    Move1();
}

void Mover::Move1()
{
    _lastPos = _pos;
    
    _pos += _vel;
}
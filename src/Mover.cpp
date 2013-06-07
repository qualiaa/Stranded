/* 
 * File:   Mover.cpp
 * Author: jamie
 * 
 * Created on 17 December 2011, 18:12
 */

#include "Mover.hpp"

Mover::Mover(Vectorf const& pos)
:Entity(pos)
{
    _vel = {0,0};
    _speed = 2;
}

Mover::~Mover() {}

void Mover::update()
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
    
    move1();
}

void Mover::move1()
{
    _lastPos = _pos;
    
    _pos += _vel;
}

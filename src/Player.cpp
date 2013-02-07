#include "Player.h"
#include "GameState.h"

#include <iostream>

Player::Player(float x, float y,MainState* state):Mover(x,y,state,ENT_PLAYER, ROT_DOWN)
{
    _frame = 6;
    _animTime = 100;
    _hitBox.w = 21;
    _hitBox.h = 5;
    _hitBox.x = _pos.x + 21;
    _hitBox.y = _pos.y + 58;

    _mapPos = Vector(0,0);
    
    _mState = state;
}

Player::~Player() {}

void Player::Update()
{
    Mover::Update();
    _hitBox.x = _pos.x + 21;
    _hitBox.y = _pos.y + 58;
    
    if(_vel.x > 0)
    {
        _rotation = ROT_RIGHT;
    }
    else if(_vel.x < 0)
    {
        _rotation = ROT_LEFT;
    }
    if(_vel.y > 0)
    {
        _rotation = ROT_DOWN;
    }
    else if(_vel.y < 0)
    {
        _rotation = ROT_UP;
    }
    if(_movingX || _movingY)
    {
	if(_movingX)
	{
		_numFrames = 8;
                if(_frame > 8)
                {
                    _frame = 1;
                }
	}
        if(_movingY)
	{
		_numFrames = 10;
	}

        Animate();
        if(_frame == 0)
	{
            _frame = 1;
	}
    }
    else
    {
        _frame = 0;
    }
    
    CheckSides();
}

void Player::Move(Rotation rot, bool moving)
{        
    if(moving)
    {
        switch(rot)
        {
            case ROT_UP:
                _vel.y -= _speed;
                break;
            case ROT_DOWN:
                _vel.y += _speed;
                break;
            case ROT_LEFT:
                _vel.x -=  _speed;
                break;
            case ROT_RIGHT:
                _vel.x += _speed;
                break;
            default:
                break;
        }
    }
    else
    {
        switch(rot)
        {
            case ROT_UP:
                _vel.y += _speed;
                break;
            case ROT_DOWN:
                _vel.y -= _speed;
                break;
            case ROT_LEFT:
                _vel.x += _speed;
                break;
            case ROT_RIGHT:
                _vel.x -= _speed;
                break;
            default:
                break;
        }
    }
}

void Player::CheckSides()
{
    if(_hitBox.x < 0)
    {
        if(_mapPos.x > 0)
        {
            _mapPos.x = _mapPos.x - 1;
	    _pos.x = 576 + 21;
            _lastPos.x = 700;
	    _hitBox.x = _pos.x + 21;

            _mState->ChangeRoom(_mapPos);
        }
        else
        {
            _pos.x = _lastPos.x;
            _vel.x = 0;
        }
    }
    if(_hitBox.x + _hitBox.w >= 640)
    {
        if(_mapPos.x < 3)
        {
            _mapPos.x = _mapPos.x + 1;
            _pos.x = 0 - 21;
            _lastPos.x = -100;
	    _hitBox.x = _pos.x + 21;

            _mState->ChangeRoom(_mapPos);
        }
        else
        {
            _pos.x = _lastPos.x;
            _vel.x = 0;
        }
    }
    if(_hitBox.y < 0)
    {
        if(_mapPos.y > 0)
        {
            _mapPos.y = _mapPos.y - 1;
            _pos.y = 640 - 64;
            _lastPos.y = 700;
	    _hitBox.y = _pos.y + 58;

            _mState->ChangeRoom(_mapPos);
        }
        else
        {
            _pos.y = _lastPos.y;
            _vel.y = 0;
        }
    }
    if(_hitBox.y + _hitBox.h >= 640)
    {
        if(_mapPos.y < 3)
        {
            _mapPos.y = _mapPos.y + 1;
            _pos.y = 0 - 58;
            _lastPos.y = -100;
	    _hitBox.y = _pos.y + 58;

            _mState->ChangeRoom(_mapPos);
        }
        else
        {
            _pos.y = _lastPos.y;
            _vel.y = 0;
        }
    }
}

void Player::IsInside(Entity* ent)
{    
    int left = _hitBox.x;
    int right = _hitBox.x + _hitBox.w;
    int top = _hitBox.y;
    int bottom = _hitBox.y + _hitBox.h;

    int entLeft = ent->GetHitBox().x;
    int entRight = entLeft + ent->GetHitBox().w;
    int entTop = ent->GetHitBox().y;
    int entBottom = entTop + ent->GetHitBox().h;

    if(ent->IsImpediment())
    {
        if(left < entRight)
        {
            _pos.x = _lastPos.x;
            _vel.x = 0;
        }
        else if(right > entLeft)
        {
            _pos.x = _lastPos.x;
            _vel.x = 0;
        }
        if(top < entBottom)
        {
            _pos.y = _lastPos.y;
            _vel.y = 0;
        }
        else if(bottom > entTop)
        {
            _pos.y = _lastPos.y;
            _vel.y = 0;
        }
        std::cout << "Collision!" << std::endl;
    }
    
    switch(ent->GetEntType())
    {
        case ENT_BAMBOO:
            if(ent->GetRotation() == ROT_NONE)
            {
                _state->AddEntity(new TextObject(50,600, _state,ENT_TEXT_SMALL, "You found some bamboo!", 1000));
            }
            break;
        default:
            break;
    }
    
    CheckSides();
}

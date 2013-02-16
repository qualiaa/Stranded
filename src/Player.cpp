#include "Player.hpp"

#include <iostream>
#include "Engine/ServiceLocator.hpp"
#include "MainState.hpp"
#include "Room.hpp"
#include "TextObject.hpp"

Player::Player(Vector const& pos )
:Mover( pos ), 
    _rotation( 1 ), 
    _mapPos( {0, 0} ), 
    _mState( NULL )
{
    _texture = ServiceLocator::getRender()->getTexture( "player" );
    _hitBox.w = 21;
    _hitBox.h = 5;
    _hitBox.x = _pos.x + 21;
    _hitBox.y = _pos.y + 58;

    _anim = Animation( _texture, { 64, 64 } );
    _anim.add( "up",    { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },           100 );
    _anim.add( "right", { 11, 12, 13, 14, 15, 16, 17, 18, 19 },         100 );
    _anim.add( "down",  { 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30 }, 100 );
    _anim.add( "left",  { 31, 32, 33, 34, 35, 36, 37, 38, 39 },         100 );
}

Player::~Player() {}

void Player::update()
{
    Mover::update();
    _hitBox.x = _pos.x + 21;
    _hitBox.y = _pos.y + 58;

    if(_vel.x > 0)
    {
        _rotation = 1;
    }
    else if(_vel.x < 0)
    {
        _rotation = 2;
    }
    if(_vel.y > 0)
    {
        _rotation = 3;
    }
    else if(_vel.y < 0)
    {
        _rotation = 0;
    }
    if(_movingX || _movingY)
    {
        switch( _rotation )
        {
            case 0: _anim.play( "up" );
            case 1: _anim.play( "right" );
            case 2: _anim.play( "down" );
            case 3: _anim.play( "left" );
            default: break;
        }
    }
    else
    {
        _anim.stop();
    }

    checkSides();
}

void Player::move(int rotation, bool moving)
{
    if(moving)
    {
        switch(rotation)
        {
            case 0:
                _vel.y -= _speed;
                break;
            case 1:
                _vel.x += _speed;
                break;
            case 2:
                _vel.y += _speed;
                break;
            case 3:
                _vel.x -=  _speed;
                break;
            default:
                break;
        }
    }
    else
    {
        _vel = {0, 0};
        /*switch(rot)
        {
            case 0:
                _vel.y += _speed;
                break;
            case 1:
                _vel.x -= _speed;
                break;
            case 2:
                _vel.y -= _speed;
                break;
            case 3:
                _vel.x += _speed;
                break;
            default:
                break;
        }*/
    }
}

void Player::checkSides()
{
    if(_hitBox.x < 0)
    {
        if(_mapPos.x > 0)
        {
            _mapPos.x = _mapPos.x - 1;
	        _pos.x = 576 + 21;
            _lastPos.x = 700;
	        _hitBox.x = _pos.x + 21;

            _mState->changeRoom(_mapPos);
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

            _mState->changeRoom(_mapPos);
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

            _mState->changeRoom(_mapPos);
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

            _mState->changeRoom(_mapPos);
        }
        else
        {
            _pos.y = _lastPos.y;
            _vel.y = 0;
        }
    }
}

void Player::isInside(Entity* ent)
{
    int left = _hitBox.x;
    int right = _hitBox.x + _hitBox.w;
    int top = _hitBox.y;
    int bottom = _hitBox.y + _hitBox.h;

    int entLeft   =           ent->getHitBox().x;
    int entRight  = entLeft + ent->getHitBox().w;
    int entTop    =           ent->getHitBox().y;
    int entBottom = entTop  + ent->getHitBox().h;

    if(ent->isSolid())
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

    /*switch(ent->getEntType())
    {
        //case ENT_BAMBOO:
            //if(ent->GetRotation() == ROT_NONE)
            //{
                //_state->addEntity(new TextObject(50,600, _state,ENT_TEXT_SMALL, "You found some bamboo!", 1000));
            //}
            break;
        default:
            break;
    }*/

    checkSides();
}

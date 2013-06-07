#include "Player.hpp"

#include "Engine/System/ServiceLocator.hpp"
#include "Engine/Graphics/Text.hpp"
#include "MainState.hpp"
#include "Room.hpp"

//{{{Player::Player(Vectorf const& pos, MainState* mState)
Player::Player(Vectorf const& pos, MainState* mState)
:Mover    (pos   ),
 _rotation(1     ),
 _mapPos  ({0, 0}),
 _mState  (mState)
{
    _texture = ServiceLocator::getRender()->getTexture( "player" );
    _hitBox.w = 21;
    _hitBox.h = 5;
    _hitBox.x = _pos.x + 21;
    _hitBox.y = _pos.y + 58;

    _type = "player";

    _anim = Animation( _texture, { 64, 64 } );
    _anim.add( "up",    {  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10 }, 100 );
    _anim.add( "right", { 11, 13, 14, 15, 16, 17, 18, 19, 20 },         100 );
    _anim.add( "down",  { 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 }, 100 );
    _anim.add( "left",  { 32, 33, 34, 35, 36, 37, 38, 39, 40, 41 },     100 );
    _anim.select("up");
}//}}}

//{{{void Player::update()
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
        _rotation = 3;
    }
    if(_vel.y > 0)
    {
        _rotation = 2;
    }
    else if(_vel.y < 0)
    {
        _rotation = 0;
    }
    if(_movingX || _movingY)
    {
        switch( _rotation )
        {
            case 0: _anim.select("up");    break; 
            case 1: _anim.select("right"); break; 
            case 2: _anim.select("down");  break; 
            case 3: _anim.select("left");  break; 
            default: break;
        }

        _anim.play();
    }
    else
    {
        _anim.stop();
    }

    checkSides();
}//}}}

//{{{void Player::draw(IRender *const render)
void Player::draw(IRender *const render)
{ 
    _anim.draw(render, _pos);
}//}}}

//{{{void Player::move(int rotation, bool moving)
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
                _vel.x -= _speed;
                break;
            default:
                break;
        }
    }
    else
    {
        switch(rotation)
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
        }
    }
}//}}}

//TODO Remove magic numbers
//{{{void Player::checkSides()
void Player::checkSides()
{
    if(_hitBox.x < 0)
    {
        if(_mapPos.x > 0)
        {
            _mapPos.x = _mapPos.x - 1;//Move player to next room
            _pos.x = 576 + 21;
            _lastPos.x = 700;
            _hitBox.x = _pos.x + 21;

            _mState->changeRoom(_mapPos);
        }
        else
        {
            _pos.x = _lastPos.x;
            //_vel.x = 0;
        }
    }
    if(_hitBox.x + _hitBox.w >= 640)
    {
        if(_mapPos.x < 3)
        {
            _mapPos.x = _mapPos.x + 1;//Move player to next room
            _pos.x = 0 - 21;
            _lastPos.x = -100;
            _hitBox.x = _pos.x + 21;

            _mState->changeRoom(_mapPos);
        }
        else
        {
            _pos.x = _lastPos.x;
            //_vel.x = 0;
        }
    }
    if(_hitBox.y < 0)
    {
        if(_mapPos.y > 0)
        {
            _mapPos.y = _mapPos.y - 1; //Move player to next room
            _pos.y = 640 - 64;
            _lastPos.y = 700;
            _hitBox.y = _pos.y + 58;

            _mState->changeRoom(_mapPos);
        }
        else
        {
            _pos.y = _lastPos.y;
            //_vel.y = 0;
        }
    }
    if(_hitBox.y + _hitBox.h >= 640)
    {
        if(_mapPos.y < 3)
        {
            _mapPos.y = _mapPos.y + 1; //Move player to next room
            _pos.y = 0 - 58;
            _lastPos.y = -100;
            _hitBox.y = _pos.y + 58;

            _mState->changeRoom(_mapPos);
        }
        else
        {
            _pos.y = _lastPos.y;
            //_vel.y = 0;
        }
    }
}//}}}

//{{{void Player::isInside(Entity* ent)
void Player::isInside(Entity* ent)
{
    int left      = _hitBox.x;
    int right     = _hitBox.x + _hitBox.w;
    int top       = _hitBox.y;
    int bottom    = _hitBox.y + _hitBox.h;

    int entLeft   =           ent->getHitBox().x;
    int entRight  = entLeft + ent->getHitBox().w;
    int entTop    =           ent->getHitBox().y;
    int entBottom = entTop  + ent->getHitBox().h;

    if(ent->isSolid())
    {
        if(left < entRight)
        {
            _pos.x = _lastPos.x;
            //_vel.x = 0;
        }
        else if(right > entLeft)
        {
            _pos.x = _lastPos.x;
            //_vel.x = 0;
        }
        if(top < entBottom)
        {
            _pos.y = _lastPos.y;
            //_vel.y = 0;
        }
        else if(bottom > entTop)
        {
            _pos.y = _lastPos.y;
            //_vel.y = 0;
        }

        _anim.stop();
    }

    if(ent->getType().compare("bamboo") == 0)
    {
        /*_state->addEntity(new Text({50,600},
                                   "You found some bamboo!",
                                   1000));*/
    }

    //checkSides();
}//}}}

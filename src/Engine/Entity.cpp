#include "Entity.hpp"

#include "GameState.hpp"

int Entity::_numEnts = 0;

Entity::Entity( Vector const& pos )
: _actorID ( _numEnts++ ),
  _pos     ( pos ),
  _texture ( NULL ),
  //_state   ( state ),
  _solid   ( false ),
  _visible ( true )
{
    //_actorID = _numEnts++;

    //_pos = pos;
    //_hitBox.x  = _pos.x;
    //_hitBox.y  = _pos.y;

    //_display = true;
    //_solid = false;

    //_state = state;
}

Entity::~Entity() { }

//Default draw function
void Entity::draw(IRender *const render)
{
    if( _texture )
    {
        render->draw( _texture, _pos );
    } 
}

void Entity::setState( GameState *const state )
{
    _state = state;
}

void Entity::setPos( Vector const& pos )
{
    _pos = pos;
}

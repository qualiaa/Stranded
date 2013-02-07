#include "Entity.h"

int Entity::_numEnts = 0;

Entity::Entity(float x, float y,GameState* state, EntityType entType, Rotation rot)
{
    _actorID = _numEnts++;

    _pos.x = x;
    _pos.y = y;
    _hitBox.x = x;
    _hitBox.y = y;
    _hitBox.h = TILE_SIZE - 1;
    _hitBox.w = TILE_SIZE - 1;
    _texWidth = 1;
    _texHeight = 1;

    _entType = entType;
    _rotation = rot;
    _display = true;

    _animTime = 0;
    _frame = 0;
    _numFrames = 0;
    
    _state = state;
    
    _impediment = false;
}

Entity::~Entity() { }

void Entity::Draw()
{
    if(_display)
    {
		Render::Instance()->DrawEntity(_entType, _pos, _rotation,
                        _frame, _texHeight, _texWidth);
    }
}

void Entity::Animate()
{
    if(_animTimer.GetTicks() > _animTime || !_animTimer.IsStarted())
    {
        _frame++;

        if(_frame > _numFrames)
        {
            _frame = 0;
        }

        _animTimer.Start();
    }
}

void Entity::Destroy()
{
    _state->RemoveEntity(this);
}
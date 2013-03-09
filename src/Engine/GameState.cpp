#include "GameState.hpp"

#include <iostream>
#include "Entity.hpp"

GameState::GameState()
: _initialized ( false ) { }

GameState::~GameState() { }

void GameState::addEntity(Entity *const ent)
{
    for ( auto _ent : _entities )
    {
        if(ent == _ent)
        {
            std::cout<< "Entity already added." << std::endl;
            return;
        }
    }

    ent->setState( this );
    _entities.push_back(ent);
}

void GameState::removeEntity(Entity *const ent)
{
    //TODO Replaces with algo
    for (unsigned int i = 0; i < _entities.size(); i++)
    {
        if(ent == _entities[i])
        {
            std::vector<Entity*>::iterator iter = _entities.begin()+i;
            delete(_entities[i]);
            _entities.erase(iter);
        }
    }
}

void GameState::update()
{
    for ( auto ent : _entities )
    {
        ent->update();
    }
}

void GameState::draw(IRender *const render)
{
    for ( auto ent : _entities )
    {
        ent->draw(render);
    }
}

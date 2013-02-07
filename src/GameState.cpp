#include "GameState.h"

#include <iostream>

GameState::GameState()
{
	_loaded = false;
}

GameState::~GameState(){}

void GameState::AddEntity(Entity *ent)
{
    for (unsigned int i = 0; i < _entities.size(); i++)
    {
        if(ent == _entities[i])
        {
            std::cout<< "Entity already added." << std::endl;
            return;
        }
    }
    _entities.push_back(ent);
}

void GameState::RemoveEntity(Entity *ent)
{
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

void GameState::Update()
{
    for (unsigned int i = 0; i < _entities.size(); i++)
    {
        _entities[i]->Update();
    }
}

void GameState::Draw()
{
    for (unsigned int i = 0; i < _entities.size(); i++)
    {
        _entities[i]->Draw();
    }
}

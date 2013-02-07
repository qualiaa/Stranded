/* 
 * File:   MainState.cpp
 * Author: jamie
 * 
 * Created on 25 December 2011, 07:50
 */

#include "MainState.h"

#include <iostream>

MainState::MainState() 
{
}

MainState::~MainState()
{
    std::cout << "Unloading World..." << std::endl;
    for (unsigned int i = 0; i < _rooms.size(); i++)
    {
        delete(_rooms[i]);
    }
    _rooms.clear();
}

int MainState::Load()
{
    if(!_loaded)
    {
        _loaded = true;
        
        _player = new Player(8*64,8*64,this);

        std::cout << "Loading World..." << std::endl;
        if(!LoadRooms())
        {
            std::cout << "Loading World failed." << std::endl;
            return 0;
        }
        std::cout << "Loaded world successfully." << std::endl;
        _currentRoom = _rooms[0];
    }

    return 1;
}

int MainState::LoadRooms()
{
    _rooms.reserve(MAP_WIDTH*MAP_HEIGHT);

        Vector coords(0,0);

        for(int i = 0; i < MAP_HEIGHT; i++)
        {
            coords.y = i;
            for(int j = 0; j < MAP_WIDTH; j++)
            {
                coords.x = j;
                _rooms[i*MAP_WIDTH+j] = new Room(coords,_player);
                if(!_rooms[i*MAP_WIDTH+j]->Load(this))
                {
                    std::cout << "Loading Room (" << coords.x << ", " << coords.y << ") failed." << std::endl;
                    return 0;
                }
            }
        }
    return 1;
}

void MainState::ChangeRoom(Vector coords)
{
    if(coords.x == MAP_WIDTH || coords.y == MAP_HEIGHT) return;
    
    std::cout << _rooms.size() << std::endl;
    
    std::cout << coords.y << ", " << coords.x << std::endl;
    
    _currentRoom = _rooms[coords.y*MAP_WIDTH + coords.x];
    
    std::cout << "Room changed." << std::endl;
    std::cout << "Co-ordinates: (" << coords.x << ", " << coords.y << ")" << std::endl;
}

Room const* const MainState::CurrentRoom()
{
    return _currentRoom;
}

void MainState::Pause()
{
    if(_paused)
    {
        _paused = false;
    }
    else
    {
        _paused = true;
    }
}

void MainState::HandleEvents(SDL_KeyboardEvent* ke)
{    
    if(ke->type == SDL_KEYDOWN)
    {
        switch(ke->keysym.sym)
        {
            case SDLK_w:
                _player->Move(ROT_UP, true);
                break;
            case SDLK_s:
                _player->Move(ROT_DOWN, true);
                break;
            case SDLK_a:
                _player->Move(ROT_LEFT, true);
                break;
            case SDLK_d:
                _player->Move(ROT_RIGHT, true);
                break;
            case SDLK_p:
                Pause();
                break;
            default: 
                break;
        }
    }
    else
    {
        switch(ke->keysym.sym)
        {
            case SDLK_w:
                _player->Move(ROT_UP, false);
                break;
            case SDLK_s:
                _player->Move(ROT_DOWN, false);
                break;
            case SDLK_a:
                _player->Move(ROT_LEFT, false);
                break;
            case SDLK_d:
                _player->Move(ROT_RIGHT, false);
                break;
            default: 
                break;
        }
    }
    
}

void MainState::Update()
{
    if(!_paused)
    {
        _currentRoom->Update();

        for(unsigned int i = 0; i < _currentRoom->GetTiles().size(); i++)
        {
            CheckCollisions(_player,_currentRoom->GetTiles()[i]);
        }
        for(unsigned int i = 0; i < _currentRoom->GetEntities().size(); i++)
        {
            CheckCollisions(_player,_currentRoom->GetEntities()[i]);
        }

        GameState::Update();
    }
}

void MainState::Draw()
{
    _currentRoom->Draw();
    GameState::Draw();
}

void MainState::CheckCollisions(Entity* entA, Entity* entB)
{
    if (entA == entB) return;
    
    SDL_Rect A = entA->GetHitBox();
    SDL_Rect B = entB->GetHitBox();
    
    int leftA = A.x;
    int leftB = B.x;
    int rightA = A.x + A.w;
    int rightB = B.x + B.w;
    int topA = A.y;
    int topB = B.y;
    int bottomA = A.y + A.h;
    int bottomB = B.y + B.h;
    
    if(leftA > rightB) return;
    if(topA > bottomB) return;
    if(rightA < leftB) return;
    if(bottomA < topB) return;
    
    entA->IsInside(entB);
    entB->IsInside(entA);
}

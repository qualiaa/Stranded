#include "Room.h"

#include <iostream>

Room::Room(Vector &vect, Entity* player):_coords(vect)
{
    _entities.push_back(player);
}

Room::~Room()
{
    std::cout << "Deleting Room..." << std::endl;
    for(unsigned int i = 0; i < _tiles.size(); i++)
    {
        delete(_tiles[i]);
    }
    _tiles.clear();
    
    for(unsigned int j = 0; j < _entities.size(); j++)
    {
        delete(_entities[j]);
    }
}

bool Room::Load(GameState* state)
{
    std::cout << "Loading Room..." << std::endl;
    
    Vector tilePos(0,0);
    int tileID;
    int objectID;
    int rotation;
    int x = (int)_coords.x;
    int y = (int)_coords.y;
    
    std::stringstream ss;
    
    ss << "res/Room_" << x << "-" << y << ".roo";
    std::string path = ss.str();
    
    std::cout << path << std::endl;
    
    std::fstream roomFile(path.c_str());
    
    if(roomFile == NULL)
    {
        roomFile.close();
        std::cout << "File Missing" << std::endl;
        return false;
    }
    
    float float1;
    
    Object *obj = NULL;
    
    for(int i = 0; i < ROOM_SIZE*ROOM_SIZE; i++)
    {
        float1 = i + 1;
        tilePos.x = i % ROOM_SIZE;
        tilePos.y = ceil(float1/ROOM_SIZE) - 1;
        
        roomFile >> tileID;
        roomFile.ignore(1,':');
        roomFile >> rotation;
        roomFile.ignore(1,'(');
        roomFile >> objectID;
        roomFile.ignore(1,')');
        
        if(roomFile.fail())
        {
            std::cout << "Room file flawed." << std::endl;
            roomFile.close();
            return false;
        }
        
        _tiles.push_back(new Tile(tilePos.x,tilePos.y,state,(EntityType)tileID,(Rotation)rotation));
        
        float objX = tilePos.x*TILE_SIZE;
        float objY = tilePos.y*TILE_SIZE;
        
        switch(objectID)
        {
            case NULL_ENTITY:
                obj = NULL;
                break;
            case ENT_BAMBOO:
                obj = new BambooObject(objX,objY,state);
                break;
            case ENT_TREE_PALM:
                obj = new PalmTreeObject(objX,objY,state);
                break;
            case ENT_TREE_SMALL:
                obj = new SmallTreeObject(objX,objY,state);
                break;
            case ENT_TREE_LARGE:
                obj = new LargeTreeObject(objX,objY,state);
                break;
            case ENT_ROCK_LARGE:
                obj = new LargeRockObject(objX,objY,state);
                break;
            case ENT_ROCK_SMALL:
                obj = new SmallRockObject(objX,objY,state);
                break;
            default:
                obj = new Object(objX,objY,state,(EntityType)objectID,(Rotation)0);
                break;
        }
        
        if(obj != NULL)
        {
            _entities.push_back(obj);
        }
    }
    
    roomFile.close();
    return true;
}

void Room::HandleInput(SDL_KeyboardEvent* ke)
{
}

void Room::Update()
{
    for (unsigned int i = 0; i < _tiles.size(); i++)
    {
        _tiles[i]->Update();
    }
    for (unsigned int j = 0; j < _entities.size(); j++)
    {
        _entities[j]->Update();
    }
}

void Room::Draw()
{
    for (unsigned int i = 0; i < _tiles.size(); i++)
    {
        _tiles[i]->Draw();
    }
    
    for(int j = 0; j < 640; j++)
    {
        for(unsigned int i = 0; i < _entities.size(); i++)
        {
            if(_entities[i]->GetHitBox().y == j)
            {
                _entities[i]->Draw();
            }
        }
                
    }
}

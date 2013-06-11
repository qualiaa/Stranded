#include "Room.hpp"

#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Engine/System/Game.hpp"
#include "Engine/Utility/Vector.hpp"
#include "Player.hpp"
#include "Object.hpp"
#include "LargeTreeObject.hpp"
#include "SmallTreeObject.hpp"
#include "PalmTreeObject.hpp"
#include "BambooObject.hpp"
#include "LargeRockObject.hpp"
#include "SmallRockObject.hpp"

//TODO Put this in a global settings class or load from Tiled
#define ROOM_SIZE 10

//TODO Replace this
//{{{enum EntityType
enum EntityType
{
    NULL_ENTITY = 0,
    ENT_TEXT_BIG = 1,
    ENT_TEXT_SMALL = 2,
    ENT_PLAYER = 3,
    ENT_TREE_SMALL = 10,
    ENT_TREE_LARGE = 11,
    ENT_TREE_PALM = 12,
    ENT_ROCK_SMALL = 13,
    ENT_ROCK_LARGE = 14,
    ENT_BOULDER = 15,
    ENT_OCEAN_ROCK = 16,
    ENT_HUT = 17,
    ENT_SHIPWRECK = 18,
    ENT_CRATE = 19,
    ENT_STONE_TABLE = 20,
    ENT_BAMBOO = 21,
    TILE_GRASS = 100,
    TILE_WOODLAND = 200,
    TILE_SAND = 300,
    TILE_SAND_WATER = 400,
    TILE_WATER = 500,
};//}}}

Room::Room(Vectori const& coords)
:_coords(coords), _currentRoom(false) { }

//{{{Room::~Room()
Room::~Room()
{
    //TODO this will totally segfault right now
    for(auto tile : _tiles)
    {
        delete(tile);
    }

    for(auto ent : _entities)
    {
        delete(ent);
    }
}//}}}

/* Dear Christ this is a nightmare.
 * What the hell was I thinking? */

//{{{bool Room::load(GameState *const state)
bool Room::load(State *const state)
{
    Game::Instance()->log("Loading Room...");

    Vectorf tilePos = {0,0};
    int tileID;
    int objectID;
    int rotation;
    int x = (int)_coords.x;
    int y = (int)_coords.y;

    std::stringstream ss;

    ss << "res/Room_" << x << "-" << y << ".roo";
    std::string path = ss.str();

    Game::Instance()->log(path);

    std::fstream roomFile(path.c_str());

    if(roomFile == NULL)
    {
        roomFile.close();
        Game::Instance()->log("File Missing");
        return false;
    }

    float float1;

    _tiles.reserve( ROOM_SIZE*ROOM_SIZE );

    Object* obj = NULL;

    for(int i = 0; i < ROOM_SIZE*ROOM_SIZE; ++i)
    {
        float1    = i + 1; //WHAT THE FUCK
        tilePos.x = i % ROOM_SIZE;
        tilePos.y = ceil(float1/ROOM_SIZE) - 1;

        roomFile >> tileID  ; roomFile.ignore(1,':');
        roomFile >> rotation; roomFile.ignore(1,'(');
        roomFile >> objectID; roomFile.ignore(1,')');

        if(roomFile.fail())
        {
            Game::Instance()->log("Room file flawed.");
            roomFile.close();
            return false;
        }
        _tiles.push_back(new Tile(tilePos, tileID, rotation));

        Vectorf objPos = { tilePos.x*Tile::TILE_SIZE,tilePos.y*Tile::TILE_SIZE };

        switch(objectID)
        {
            case NULL_ENTITY:
                obj = NULL;
                break;
            case ENT_BAMBOO:
                obj = new BambooObject( {} );
                break;
            case ENT_TREE_PALM:
                obj = new PalmTreeObject( {} );
                break;
            case ENT_TREE_SMALL:
                obj = new SmallTreeObject( {} );
                break;
            case ENT_TREE_LARGE:
                obj = new LargeTreeObject( {} );
                break;
            case ENT_ROCK_LARGE:
                obj = new LargeRockObject( {} );
                break;
            case ENT_ROCK_SMALL:
                obj = new SmallRockObject( {} );
                break;
            default:
                //obj = new Object( {}, "" );
                obj = NULL;
                break;
        }

        if(obj != NULL)
        {
            obj->setPos( objPos );
            obj->setState( state );
            _entities.push_back(obj);
        }
    }

    roomFile.close();

    return true;
}//}}}

void Room::handleInput(SDL_KeyboardEvent *const ke) { }

//{{{void Room::update()
void Room::update()
{
    for (unsigned int i = 0; i < _tiles.size(); i++)
    {
        _tiles[i]->update();
    }
    for (unsigned int i = 0; i < _entities.size(); i++)
    {
        _entities[i]->update();
    }
}//}}}

//{{{void Room::draw(IRender *const render)
void Room::draw(IRender *const render)
{
    for (unsigned int i = 0; i < _tiles.size(); i++)
    {
        _tiles[i]->draw(render);
    }

    //TODO Get screen height from settings class
    for(unsigned int i = 0; i < 640; i++)
    {
        for(auto entity : _entities )
        {
            if(entity->getPos().y + entity->getHitBox().y == ( int ) i)
            {
                entity->draw(render);
            }
        } 
    }
}//}}}

//{{{Includes
#include "MainState.hpp"

#include <iostream>
#include <algorithm>
#include "Engine/System/ServiceLocator.hpp"
#include "Room.hpp"
#include "Player.hpp"
#include "Tile.hpp"
//}}}

//TODO Put this in a global settings class or load from Tiled
//{{{Defines
#define MAP_WIDTH 4
#define MAP_HEIGHT 4
//}}}

MainState::MainState()
:_currentRoom(NULL),
 _player(NULL),
 _paused(false) {}

//{{{MainState::~MainState()
MainState::~MainState()
{
    std::cout << "Unloading World..." << std::endl;

    for (unsigned int i = 0; i < _rooms.size(); ++i)
    {
        delete(_rooms[i]);
    }
    _rooms.clear();

    delete _player;
    _entities.clear();
}//}}}

//{{{bool MainState::initialize()
bool MainState::initialize()
{
    std::cout << "Loading main state" << std::endl;
    if(!_initialized)
    {
        _initialized = true;

        /* Load graphics */
        IRender* render = ServiceLocator::getRender();

        _initialized |= !render->loadImage( "font"      , "res/Font.png"           );
        _initialized |= !render->loadImage( "fontsmall" , "res/FontSmall.png"      );
        _initialized |= !render->loadImage( "grass"     , "res/GrassTiles.png"     );
        _initialized |= !render->loadImage( "sand"      , "res/SandTiles.png"      );
        _initialized |= !render->loadImage( "sandwater" , "res/SandWaterTiles.png" );
        _initialized |= !render->loadImage( "water"     , "res/WaterTiles.png"     );
        _initialized |= !render->loadImage( "player"    , "res/Player.png"         );
        _initialized |= !render->loadImage( "smalltree" , "res/SmallTree.png"      );
        _initialized |= !render->loadImage( "largetree" , "res/LargeTree.png"      );
        _initialized |= !render->loadImage( "oceanrock" , "res/OceanRock.png"      );
        _initialized |= !render->loadImage( "bamboo"    , "res/Bamboo.png"         );
        _initialized |= !render->loadImage( "palmtree"  , "res/PalmTree.png"       );
        _initialized |= !render->loadImage( "smallrock" , "res/SmallRock.png"      );
        _initialized |= !render->loadImage( "largerock" , "res/LargeRock.png"      );

        if(!_initialized)
        {
            std::cout << "Loading MainState failed" << std::endl;
            return false;
        }

        //Create a new player
        _player = new Player({ static_cast<float>(8*Tile::TILE_SIZE),
                               static_cast<float>(8*Tile::TILE_SIZE) },
                             this );
        //addEntity(_player);

        std::cout << "Loading World..." << std::endl;
        if(!loadRooms())
        {
            _initialized = false;
            std::cout << "Loading World failed." << std::endl;
        }
        std::cout << "Loaded world successfully." << std::endl;
        changeRoom({0,0});
    }

    return _initialized;
}//}}}

//{{{bool MainState::loadRooms()
bool MainState::loadRooms()
{
    _rooms.reserve(MAP_WIDTH*MAP_HEIGHT);

    Vectori coords({0,0});

    for(int i = 0; i < MAP_HEIGHT; i++)
    {
        coords.y = i;
        for(int j = 0; j < MAP_WIDTH; j++)
        {
            coords.x = j;
            //_rooms[i*MAP_WIDTH+j] = new Room(coords,_player);
            _rooms.push_back(new Room(coords));
            if(!_rooms.back()->load(this))
            {
                std::cout << "Loading Room (" << coords.x << ", " << coords.y << ") failed." << std::endl;
                return false;
            }
        }
    }

    std::cout << "Created " << _rooms.size() << " rooms" << std::endl;
    return true;
} //}}}

//{{{void MainState::changeRoom(Vector const& coords)
void MainState::changeRoom(Vectori const& coords)
{
    if(coords.x == MAP_WIDTH || coords.y == MAP_HEIGHT) return;

    _currentRoom = _rooms[coords.y*MAP_WIDTH + coords.x];

    std::vector<Entity*>& ents = _currentRoom->GetEntities();
    std::vector<Tile*>& tiles = _currentRoom->GetTiles();

    _entities.clear();
    _entities.reserve(ents.size() + tiles.size());
    _entities.insert(_entities.end(), tiles.begin(), tiles.end());
    _entities.insert(_entities.end(), ents.begin(), ents.end());
    addEntity(_player);
}//}}}

//{{{Room const* const MainState::currentRoom()
Room const* MainState::currentRoom()
{
    return _currentRoom;
}//}}}

//{{{void MainState::pause()
void MainState::pause()
{
    if(_paused)
    {
        _paused = false;
    }
    else
    {
        _paused = true;
    }
}//}}}

//{{{void MainState::handleEvents(SDL_KeyboardEvent *const ke)
void MainState::handleEvents(SDL_KeyboardEvent *const ke)
{
    if(ke->type == SDL_KEYDOWN)
    {
        switch(ke->keysym.sym)
        {
            //TODO Improve this
            case SDLK_w:
                _player->move(0, true);
                break;
            case SDLK_s:
                _player->move(2, true);
                break;
            case SDLK_a:
                _player->move(3, true);
                break;
            case SDLK_d:
                _player->move(1, true);
                break;
            case SDLK_p:
                pause();
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
                _player->move(0, false);
                break;
            case SDLK_s:
                _player->move(2, false);
                break;
            case SDLK_a:
                _player->move(3, false);
                break;
            case SDLK_d:
                _player->move(1, false);
                break;
            default:
                break;
        }
    }
}//}}}

//{{{void MainState::update()
/*void MainState::update()
{
    if(!_paused)
    {
        _currentRoom->update();

        for(unsigned int i = 0; i < _currentRoom->GetTiles().size(); ++i)
        {
            checkCollisions(_player,_currentRoom->GetTiles()[i]);
        }
        for(unsigned int i = 0; i < _currentRoom->GetEntities().size(); ++i)
        {
            checkCollisions(_player,_currentRoom->GetEntities()[i]);
        }

        //GameState::update();
    }
}*///}}}

void MainState::draw(IRender* render)
{
    //Find first non-tile element in (hopefully) sorted list
    auto firstEnt = std::partition_point(_entities.begin(), _entities.end(),
                                         [](Entity* ent)
    {
        return ent->getType() == "tile";
    });

    auto depthTest = [](Entity* A, Entity* B)
    {
        return A->getPos().y + A->getHitBox().y <
               B->getPos().y + B->getHitBox().y;
    };

    //Sort all non-tile elements by bottom edge of hitbox
    if(!std::is_sorted(firstEnt, _entities.end(), depthTest))
    {
        std::sort(firstEnt, _entities.end(), depthTest);
    }

    for(auto entity : _entities )
    {
        entity->draw(render);
    }
}

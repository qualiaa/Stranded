#include "MainState.hpp"

#include <iostream>
#include "Engine/ServiceLocator.hpp"
#include "Room.hpp"
#include "Player.hpp"
#include "Tile.hpp"

//TODO Put this in a global settings class or load from Tiled
#define MAP_WIDTH 4
#define MAP_HEIGHT 4

MainState::MainState() { }

MainState::~MainState()
{
    std::cout << "Unloading World..." << std::endl;
    for (unsigned int i = 0; i < _rooms.size(); i++)
    {
        delete(_rooms[i]);
    }
    _rooms.clear();
}

bool MainState::initialize()
{
    std::cout << "Loading main state" << std::endl;
    if(!_initialized)
    {
        /* Load graphics */
        IRender* render = ServiceLocator::getRender();

        bool imageError = false;

        imageError |= !render->loadImage( "font"      , "res/Font.png"           );
        imageError |= !render->loadImage( "fontsmall" , "res/FontSmall.png"      );
        imageError |= !render->loadImage( "grass"     , "res/GrassTiles.png"     );
        imageError |= !render->loadImage( "sand"      , "res/SandTiles.png"      );
        imageError |= !render->loadImage( "sandwater" , "res/SandWaterTiles.png" );
        imageError |= !render->loadImage( "water"     , "res/WaterTiles.png"     );
        imageError |= !render->loadImage( "player"    , "res/Player.png"         );
        imageError |= !render->loadImage( "smalltree" , "res/SmallTree.png"      );
        imageError |= !render->loadImage( "largetree" , "res/LargeTree.png"      );
        imageError |= !render->loadImage( "oceanrock" , "res/OceanRock.png"      );
        imageError |= !render->loadImage( "bamboo"    , "res/Bamboo.png"         );
        imageError |= !render->loadImage( "palmtree"  , "res/PalmTree.png"       );
        imageError |= !render->loadImage( "smallrock" , "res/SmallRock.png"          );
        imageError |= !render->loadImage( "largerock" , "res/LargeRock.png"      );

        if( imageError )
        {
            std::cout << "Returning false" << std::endl;
            return false;
        } 

        _player = new Player( { ( double )8*Tile::TILE_SIZE,( double )8*Tile::TILE_SIZE } );

        //TODO Find out what I did here
        _player->setState( this );

        std::cout << "Loading World..." << std::endl;
        if(!loadRooms())
        {
            std::cout << "Loading World failed." << std::endl;
            return false;
        }
        std::cout << "Loaded world successfully." << std::endl;
        _currentRoom = _rooms[0];

        _initialized = true;
    }

    return _initialized;
}

bool MainState::loadRooms()
{
    _rooms.reserve(MAP_WIDTH*MAP_HEIGHT);

    Vector coords({0,0});

    for(int i = 0; i < MAP_HEIGHT; i++)
    {
        coords.y = i;
        for(int j = 0; j < MAP_WIDTH; j++)
        {
            coords.x = j;
            _rooms[i*MAP_WIDTH+j] = new Room(coords,_player);
            if(!_rooms[i*MAP_WIDTH+j]->load(this))
            {
                std::cout << "Loading Room (" << coords.x << ", " << coords.y << ") failed." << std::endl;
                return false;
            }
        }
    }

    return true;
}

void MainState::changeRoom(Vector const& coords)
{
    if(coords.x == MAP_WIDTH || coords.y == MAP_HEIGHT) return;

    std::cout << _rooms.size() << std::endl;

    std::cout << coords.y << ", " << coords.x << std::endl;

    _currentRoom = _rooms[coords.y*MAP_WIDTH + coords.x];

    std::cout << "Room changed." << std::endl;
    std::cout << "Coordinates: (" << coords.x << ", " << coords.y << ")" << std::endl;
}

Room const* const MainState::currentRoom()
{
    return _currentRoom;
}

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
}

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

}

void MainState::update()
{
    if(!_paused)
    {
        _currentRoom->update();

        /*
        for(unsigned int i = 0; i < _currentRoom->GetTiles().size(); i++)
        {
            //CheckCollisions(_player,_currentRoom->GetTiles()[i]);
        }
        for(unsigned int i = 0; i < _currentRoom->GetEntities().size(); i++)
        {
            //CheckCollisions(_player,_currentRoom->GetEntities()[i]);
        }
        */

        GameState::update();
    }
}

void MainState::draw(IRender *const render)
{
    GameState::draw(render);
    _currentRoom->draw(render);
}

//TODO Move into Entity
void MainState::checkCollisions(Entity* entA, Entity* entB)
{
    if (entA == entB) return;

    Rect const& A = entA->getHitBox();
    Rect const& B = entB->getHitBox();

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

    entA->isInside(entB);
    entB->isInside(entA);
}

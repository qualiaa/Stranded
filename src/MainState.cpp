#include "MainState.hpp"

#include <algorithm>
#include "Engine/System/ServiceLocator.hpp"
#include "Engine/System/Game.hpp"
#include "Room.hpp"
#include "Player.hpp"
#include "Tile.hpp"

//TODO Put this in a global settings class or load from Tiled
#define MAP_WIDTH 4
#define MAP_HEIGHT 4

MainState::MainState()
   :currentRoom_(NULL),
    paused_(false)
{
    bool initialized = true;
    Game::log() << "Loading main state" << std::endl;

    /* Load graphics */
    IRender* render = ServiceLocator::getRender();

    initialized &= render->loadImage( "font"      , "res/Font.png"           );
    initialized &= render->loadImage( "fontsmall" , "res/FontSmall.png"      );
    initialized &= render->loadImage( "grass"     , "res/GrassTiles.png"     );
    initialized &= render->loadImage( "sand"      , "res/SandTiles.png"      );
    initialized &= render->loadImage( "sandwater" , "res/SandWaterTiles.png" );
    initialized &= render->loadImage( "water"     , "res/WaterTiles.png"     );
    initialized &= render->loadImage( "player"    , "res/Player.png"         );
    initialized &= render->loadImage( "smalltree" , "res/SmallTree.png"      );
    initialized &= render->loadImage( "largetree" , "res/LargeTree.png"      );
    initialized &= render->loadImage( "oceanrock" , "res/OceanRock.png"      );
    initialized &= render->loadImage( "bamboo"    , "res/Bamboo.png"         );
    initialized &= render->loadImage( "palmtree"  , "res/PalmTree.png"       );
    initialized &= render->loadImage( "smallrock" , "res/SmallRock.png"      );
    initialized &= render->loadImage( "largerock" , "res/LargeRock.png"      );

    if(!initialized)
    {
        throw std::runtime_error("Loading images failed");
    }

    Game::log() << "Loading World..." << std::endl;

    loadRooms();
    currentRoom_ = rooms_[0];
    player_ = new Player({ static_cast<float>(8*Tile::TILE_SIZE),
                           static_cast<float>(8*Tile::TILE_SIZE) },
                           this);
    currentRoom_->insertEntity(std::unique_ptr<Player>(player_));
}

MainState::~MainState()
{
    Game::log() << "Unloading World..." << std::endl;

    for (unsigned int i = 0; i < rooms_.size(); ++i)
    {
        delete(rooms_[i]);
    }
    rooms_.clear();

    entities_.clear();
}

void MainState::loadRooms()
{
    rooms_.reserve(MAP_WIDTH*MAP_HEIGHT);

    Vectori coords({0,0});

    for(int i = 0; i < MAP_HEIGHT; i++)
    {
        coords.y = i;
        for(int j = 0; j < MAP_WIDTH; j++)
        {
            coords.x = j;
            //rooms_[i*MAP_WIDTH+j] = new Room(coords,player_);
            rooms_.push_back(new Room(coords));
        }
    }
}

void MainState::changeRoom(Vectori const& coords)
{
    if(coords.x == MAP_WIDTH || coords.y == MAP_HEIGHT) return;

    std::unique_ptr<Entity> playerPtr = currentRoom_->releaseEntity(player_);

    currentRoom_ = rooms_[coords.y*MAP_WIDTH + coords.x]; 

    currentRoom_->insertEntity(std::move(playerPtr));
}

Room const* MainState::currentRoom()
{
    return currentRoom_;
}

void MainState::pause()
{
    if(paused_)
    {
        paused_ = false;
    }
    else
    {
        paused_ = true;
    }
}

void MainState::handleEvents(SDL_KeyboardEvent *const ke)
{
    if(ke->type == SDL_KEYDOWN)
    {
        switch(ke->keysym.sym)
        {
            case SDLK_w:
                player_->move(0, true);
                break;
            case SDLK_s:
                player_->move(2, true);
                break;
            case SDLK_a:
                player_->move(3, true);
                break;
            case SDLK_d:
                player_->move(1, true);
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
                player_->move(0, false);
                break;
            case SDLK_s:
                player_->move(2, false);
                break;
            case SDLK_a:
                player_->move(3, false);
                break;
            case SDLK_d:
                player_->move(1, false);
                break;
            default:
                break;
        }
    }
}

void MainState::update()
{
    if(!paused_)
    {
        currentRoom_->update(); 
    }
}

void MainState::draw(IRender* render)
{
    /*
    //Find first non-tile element in (hopefully) sorted list
    auto firstEnt = std::partition_point(entities_.begin(), entities_.end(),
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
    if(!std::is_sorted(firstEnt, entities_.end(), depthTest))
    {
        std::sort(firstEnt, entities_.end(), depthTest);
    }

    for(auto entity : entities_ )
    {
        entity->draw(render);
    }*/
    currentRoom_->draw(render);
}

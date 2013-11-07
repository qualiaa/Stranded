#include "MainWorld.hpp"
#include <algorithm>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <Tank/System/Game.hpp>
#include <Tank/System/Entity.hpp>
#include <Tank/Graphics/Text.hpp>
#include <Tank/Graphics/BitmapText.hpp>
#include "Room.hpp"
#include "Player.hpp"
#include "Tile.hpp"

//TODO Put this in a global settings class or load from Tiled
#define MAP_WIDTH 4
#define MAP_HEIGHT 4

MainWorld::MainWorld()
   :currentRoom_(nullptr),
    paused_(false)
{
    tank::Game::log << "Loading main state" << std::endl;

    /* Load graphics */
    font.load("res/Font.png");
    ttffont.loadFromFile("res/Vera.ttf");
    fontsmall.load("res/FontSmall.png");
    grass.load("res/GrassTiles.png");
    sand.load("res/SandTiles.png");
    sandwater.load("res/SandWaterTiles.png");
    water.load("res/WaterTiles.png");
    player.load("res/Player.png");
    smalltree.load("res/SmallTree.png");
    largetree.load("res/LargeTree.png");
    oceanrock.load("res/OceanRock.png");
    bamboo.load("res/Bamboo.png");
    palmtree.load("res/PalmTree.png");
    smallrock.load("res/SmallRock.png");
    largerock.load("res/LargeRock.png");

    tank::Game::log << "Loading World..." << std::endl;

    loadRooms();
    currentRoom_ = rooms_[0];
    const float playerPos = 8 * Tile::TILE_SIZE;
    player_ = currentRoom_->makeEntity<Player>(tank::Vectorf{playerPos, playerPos},
                                               this);

    makeEntity<tank::Entity>(tank::Vectorf{10.f, 10.f})->makeGraphic<tank::BitmapText>(font, tank::Vectoru{50, 50})->setText("HELLO");
    makeEntity<tank::Entity>(tank::Vectorf{40.f, 40.f})->makeGraphic<tank::Text>(ttffont)->setText("HELLO");
}

MainWorld::~MainWorld()
{
    tank::Game::log << "Unloading World..." << std::endl;
    /*
    for (unsigned int i = 0; i < rooms_.size(); ++i)
    {
        delete(rooms_[i]);
    }*/
    rooms_.clear();

    entities_.clear();
}

void MainWorld::loadRooms()
{
    rooms_.reserve(MAP_WIDTH*MAP_HEIGHT);

    tank::Vectori coords({0,0});

    for(int i = 0; i < MAP_HEIGHT; i++)
    {
        coords.y = i;
        for(int j = 0; j < MAP_WIDTH; j++)
        {
            coords.x = j;
            //rooms_[i*MAP_WIDTH+j] = new Room(coords,player_);
            rooms_.emplace_back(new Room(coords));
        }
    }
}

void MainWorld::changeRoom(tank::Vectori coords)
{
    if(coords.x == MAP_WIDTH || coords.y == MAP_HEIGHT) return;

    tank::observing_ptr<Room> lastRoom = currentRoom_;
    currentRoom_ = rooms_[coords.y*MAP_WIDTH + coords.x];

    lastRoom->moveEntity(currentRoom_, player_);
}

const tank::observing_ptr<Room> MainWorld::currentRoom()
{
    return currentRoom_;
}

void MainWorld::pause()
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

void MainWorld::update()
{
    if(!paused_)
    {
        currentRoom_->update();
    }
}

void MainWorld::draw()
{
    currentRoom_->draw();
    tank::World::draw();
}

tank::Image MainWorld::font;
tank::Font MainWorld::ttffont;
tank::Image MainWorld::fontsmall;
tank::Image MainWorld::grass;
tank::Image MainWorld::sand;
tank::Image MainWorld::sandwater;
tank::Image MainWorld::water;
tank::Image MainWorld::player;
tank::Image MainWorld::smalltree;
tank::Image MainWorld::largetree;
tank::Image MainWorld::oceanrock;
tank::Image MainWorld::bamboo;
tank::Image MainWorld::palmtree;
tank::Image MainWorld::smallrock;
tank::Image MainWorld::largerock;

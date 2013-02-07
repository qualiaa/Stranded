/* 
 * File:   Enums.h
 * Author: jamie
 *
 * Created on 18 December 2011, 03:34
 */

#ifndef ENUMS_H
#define	ENUMS_H


const int TILE_SIZE = 64;
const int ROOM_SIZE = 10;
const int MAP_WIDTH = 4;
const int MAP_HEIGHT = 4;
const int FRAMES_PER_SECOND = 60;

/*Entity definitions here*/

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
};

enum Rotation
{
    ROT_NONE = 0,
    ROT_UP = 1,
    ROT_RIGHT = 2,
    ROT_DOWN = 3,
    ROT_LEFT = 4,
    ROT_TOP_LEFT = 5,
    ROT_TOP_RIGHT = 6,
    ROT_BOTTOM_RIGHT = 7,
    ROT_BOTTOM_LEFT = 8    
};
#endif
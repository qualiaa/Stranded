/* 
 * File:   Inventory.h
 * Author: jamie
 *
 * Created on 12 January 2012, 15:00
 */

#ifndef INVENTORY_H
#define	INVENTORY_H

#include <vector>
#include <string>
#include "Render.h"
#include "TextObject.h"

enum Items
{
    NULL_ITEM,
    ITEM_BAMBOO,
    ITEM_COCONUT,
    NUM_ITEMS            
};

class Inventory
{
public:
    Inventory(GameState *state);
    virtual ~Inventory();

    void AddItem(Items);
    void Draw();
private:
    int _items[NUM_ITEMS];
    //Hacky Hacky
    SDL_Surface* _background;
};

#endif	/* INVENTORY_H */
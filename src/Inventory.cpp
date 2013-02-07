/* 
 * File:   Inventory.cpp
 * Author: jamie
 * 
 * Created on 12 January 2012, 15:00
 */

#include "Inventory.h"

Inventory::Inventory(GameState *state) 
{
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        _items[i] = 0;
    }
}

Inventory::~Inventory() 
{
    
}

void Inventory::AddItem(Items item)
{
    _items[item]++;
}

void Inventory::Draw()
{
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        if(_items[i] != 0)
        {
            switch(i)
            {
                case NULL_ITEM:
                    break;
                case ITEM_BAMBOO:
                    break;
                case ITEM_COCONUT:
                    break;
                default:
                    break;
            }
        }
    }
}

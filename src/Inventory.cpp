#include "Inventory.hpp"

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

void Inventory::addItem(Items item)
{
    _items[item]++;
}

/*
void Inventory::draw()
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
*/

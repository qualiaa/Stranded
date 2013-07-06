#include "Inventory.hpp"

Inventory::Inventory()
{
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        items_[i] = 0;
    }
}

Inventory::~Inventory()
{
}

void Inventory::addItem(Items item)
{
    items_[item]++;
}

/*
void Inventory::draw()
{
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        if(items_[i] != 0)
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

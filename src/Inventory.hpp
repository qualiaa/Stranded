#pragma once
#ifndef INVENTORY_H
#define	INVENTORY_H

class GameState;

class Inventory
{
public:
    Inventory(GameState *state);
    virtual ~Inventory();

    enum Items
    {
        NULL_ITEM,
        ITEM_BAMBOO,
        ITEM_COCONUT,
        NUM_ITEMS            
    };

    void addItem(Items);
    //void draw();
private:
    int _items[NUM_ITEMS];
}; 
#endif

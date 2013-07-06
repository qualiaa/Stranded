#pragma once
#ifndef INVENTORY_H
#define	INVENTORY_H

class GameState;

class Inventory
{
public:
    Inventory();
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
    int items_[NUM_ITEMS];
};
#endif

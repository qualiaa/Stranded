#include "BambooObject.hpp"

#include "Engine/GameState.hpp"
#include "Engine/Text.hpp"
#include "Tile.hpp"

BambooObject::BambooObject(Vector const& pos)
:Object( pos, "bamboo" ),
 _anim(_texture, { static_cast<double>(Tile::TILE_SIZE), 
                   static_cast<double>(Tile::TILE_SIZE) })
{
    _hitBox.x += 14;
    _hitBox.w = 24;
    _hitBox.y += 42;
    _hitBox.h = 8;
    _solid = true;

    _anim.add("normal", {0}, 0);
    _anim.add("taken",  {1}, 0);
    _anim.play("normal",false); 
}

BambooObject::~BambooObject()
{
    
}

void BambooObject::isInside(Entity* ent)
{
    if(ent->getType().compare("player") == 0)
    {
        _anim.play("taken",false);
        _type  = "bamboo_taken";
        if(_solid)
        {
            _state->addEntity(new Text({50,600},
                                       "You found some bamboo!",
                                       1000));
            _solid = false;
        }
    }
}

void BambooObject::draw(IRender* render)
{
    _anim.draw(render, _pos);
}

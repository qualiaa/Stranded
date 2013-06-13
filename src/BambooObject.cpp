#include "BambooObject.hpp"

#include "Engine/System/State.hpp"
#include "Engine/Graphics/Text.hpp"
#include "Tile.hpp"

BambooObject::BambooObject(Vectorf const& pos)
:Object( pos, "bamboo" ),
 anim_(texture_, { static_cast<float>(Tile::TILE_SIZE), 
                   static_cast<float>(Tile::TILE_SIZE) })
{
    hitbox_.x = 14;
    hitbox_.w = 24;
    hitbox_.y = 42;
    hitbox_.h = 8;
    solid_ = true;
    type_ = "bamboo";

    anim_.add("normal", {0}, 0);
    anim_.add("taken",  {1}, 0);
    anim_.select("normal",false); 
}

void BambooObject::update()
{
    if(!collide("player").empty())
    {
        anim_.select("taken",false);
        type_  = "bamboo_taken";
        if(solid_)
        {
            state_->makeEntity<Text>(Vectorf{50,600}, "You found some bamboo!", 1000);
            solid_ = false;
        }
    }
}

void BambooObject::draw(IRender* render)
{
    anim_.draw(render, pos_);
}

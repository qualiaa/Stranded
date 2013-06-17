#include "BambooObject.hpp"

#include "Engine/System/State.hpp"
#include "Engine/Graphics/Text.hpp"
#include "Tile.hpp"

BambooObject::BambooObject(Vectorf const& pos)
:Object( pos, "bamboo" ),
 anim_(getTexture(), { static_cast<float>(Tile::TILE_SIZE), 
                       static_cast<float>(Tile::TILE_SIZE) })
{
    setHitbox({14, 42, 24, 8});
    setSolid(true);
    setType("bamboo");

    anim_.add("normal", {0}, 0);
    anim_.add("taken",  {1}, 0);
    anim_.select("normal",false); 
}

void BambooObject::update()
{
    if(!collide("player").empty())
    {
        anim_.select("taken",false);
        setType("bamboo_taken");
        if(isSolid())
        {
            getState()->makeEntity<Text>(Vectorf{50,600}, "You found some bamboo!", 1000);
            setSolid(true);
        }
    }
}

void BambooObject::draw(IRender* render)
{
    anim_.draw(render, getPos());
}

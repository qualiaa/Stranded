#include "BambooObject.hpp"

#include "Engine/System/State.hpp"
#include "Engine/Graphics/Text.hpp"
#include "Tile.hpp"
#include "MainState.hpp"

BambooObject::BambooObject(tank::Vectorf pos)
    : tank::Entity(pos)
{

    setGraphic<tank::Image>(MainState::bamboo);
    getGraphic().setSize({64.f, 64.f});
    getGraphic().setClip({0, 0, 64, 64});
    setHitbox({14, 42, 24, 8});
    setSolid(true);
    setType("bamboo");
}

void BambooObject::update()
{
    if(!collide("player").empty())
    {
        getGraphic().setClip({64, 0, 64, 64});
        setType("bamboo_taken");
        if(isSolid())
        {
            //getState()->makeEntity<Text>(Vectorf{50,600}, "You found some bamboo!", 1000);
            setSolid(true);
        }
    }
}
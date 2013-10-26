#include "BambooObject.hpp"

#include <Tank/System/State.hpp>
#include <Tank/Graphics/Text.hpp>
#include "Tile.hpp"
#include "MainState.hpp"

BambooObject::BambooObject(tank::Vectorf pos)
    : Object(pos)
{
    makeGraphic<tank::Image>(MainState::bamboo);
    getGraphic()->setClip({0, 0, 64, 64});
    setHitbox({14, 42, 24, 8});
    setType("bamboo");
}

void BambooObject::update()
{
    if(!collide("player").empty())
    {
        if(getType() == "bamboo")
        {
            getGraphic()->setClip({64, 0, 64, 64});
            setType("bamboo_taken");
            //getState()->makeEntity<Text>(Vectorf{50,600}, "You found some bamboo!", 1000);
        }
    }
}

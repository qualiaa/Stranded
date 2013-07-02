#include "SmallRockObject.hpp"
#include "Engine/Graphics/Image.hpp"
#include "MainState.hpp"

SmallRockObject::SmallRockObject(tank::Vectorf pos)
    : Object(pos)
{
    setGraphic<tank::Image>(MainState::smallrock);
    setHitbox({ 12, 30, 30, 20 });
    setSolid(true);
}

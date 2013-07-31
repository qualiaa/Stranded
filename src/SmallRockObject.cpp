#include "SmallRockObject.hpp"
#include <Tank/Graphics/Image.hpp>
#include "MainState.hpp"

SmallRockObject::SmallRockObject(tank::Vectorf pos)
    : Object(pos)
{
    makeGraphic<tank::Image>(MainState::smallrock);
    setHitbox({ 12, 30, 30, 20 });
    setSolid(true);
}

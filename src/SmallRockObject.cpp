#include "SmallRockObject.hpp"
#include <Tank/Graphics/Image.hpp>
#include "MainWorld.hpp"

SmallRockObject::SmallRockObject(tank::Vectorf pos)
    : Object(pos)
{
    makeGraphic<tank::Image>(MainWorld::smallrock);
    setHitbox({ 12, 30, 30, 20 });
    setType("solid");
}

#include "LargeRockObject.hpp"

#include <Tank/Graphics/Image.hpp>
#include "MainWorld.hpp"

LargeRockObject::LargeRockObject(tank::Vectorf pos)
    : Object(pos)
{
    makeGraphic<tank::Image>(MainWorld::largerock);
    setHitbox({ 12, 12, 42, 32 });
    setType("solid");
}

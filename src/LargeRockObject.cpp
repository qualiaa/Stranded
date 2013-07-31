#include "LargeRockObject.hpp"

#include <Tank/Graphics/Image.hpp>
#include "MainState.hpp"

LargeRockObject::LargeRockObject(tank::Vectorf pos)
    : Object(pos)
{
    makeGraphic<tank::Image>(MainState::largerock);
    setHitbox({ 12, 12, 42, 32 });
    setSolid(true);
}

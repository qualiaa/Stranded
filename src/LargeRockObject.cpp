#include "LargeRockObject.hpp"

#include "Engine/Graphics/Image.hpp"
#include "MainState.hpp"

LargeRockObject::LargeRockObject(tank::Vectorf pos)
    : Object(pos)
{
    setGraphic<tank::Image>(MainState::largerock);
    setHitbox({ 12, 12, 42, 32 });
    setSolid(true);
}

#include "SmallRockObject.hpp"
#include "Engine/Graphics/Image.hpp"
#include "MainState.hpp"

SmallRockObject::SmallRockObject(tank::Vectorf pos)
    : tank::Entity(pos)
{
    setGraphic<tank::Image>(MainState::smallrock);
    setHitbox({ 12, 30, 22, 18 });
    setSolid(true);
}

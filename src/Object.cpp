#include "Object.hpp"

#include "Engine/System/Game.hpp"

Object::Object(tank::Vectorf pos)
    : tank::Entity(pos)
{ }

void Object::setHitbox(tank::Rect hb)
{
    Entity::setHitbox(hb);

    setLayer(getHitbox().y + getPos().y);
}

void Object::setPos(tank::Vectorf pos)
{
    Entity::setPos(pos);

    setLayer(getHitbox().y + getPos().y);
}

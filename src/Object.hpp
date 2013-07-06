#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "Engine/System/Entity.hpp"
#include "Engine/Utility/Vector.hpp"
#include "Engine/Utility/Rect.hpp"

class Object : public tank::Entity
{
public:
    Object(tank::Vectorf pos);

    virtual void setHitbox(tank::Rectd) override;
    virtual void setPos(tank::Vectorf) override;
};
#endif /* OBJECT_HPP */

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <Tank/System/Entity.hpp>
#include <Tank/Utility/Vector.hpp>
#include <Tank/Utility/Rect.hpp>

class Object : public tank::Entity
{
public:
    Object(tank::Vectorf pos);

    virtual void setHitbox(tank::Rectd) override;
    virtual void setPos(tank::Vectorf) override;
};
#endif /* OBJECT_HPP */

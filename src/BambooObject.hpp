#ifndef BAMBOOOBJECT_H
#define	BAMBOOOBJECT_H

#include "Engine/System/Entity.hpp"

class BambooObject : public tank::Entity
{
public:
    virtual void update();

    BambooObject(tank::Vectorf pos);
};

#endif	/* BAMBOOOBJECT_H */


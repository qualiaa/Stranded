#ifndef BAMBOOOBJECT_H
#define	BAMBOOOBJECT_H

#include "Object.hpp"

class BambooObject : public Object
{
public:
    virtual void update();

    BambooObject(tank::Vectorf pos);
};

#endif	/* BAMBOOOBJECT_H */


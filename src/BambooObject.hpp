#ifndef BAMBOOOBJECT_H
#define	BAMBOOOBJECT_H

#include "Object.hpp"

class BambooObject : public Object
{
    tank::observing_ptr<tank::Image> bambooImage_;
public:
    virtual void update();

    BambooObject(tank::Vectorf pos);
};

#endif	/* BAMBOOOBJECT_H */


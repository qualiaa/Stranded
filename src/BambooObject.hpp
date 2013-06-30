/*
 * File:   BambooObject.hpp
 * Author: jamie
 *
 * Created on 06 January 2012, 01:35
*/

#ifndef BAMBOOOBJECT_H
#define	BAMBOOOBJECT_H

#include "Engine/System/Entity.hpp"

class BambooObject : public tank::Entity
{
public:
    virtual void update();

    BambooObject(tank::Vectorf pos);
private:
};

#endif	/* BAMBOOOBJECT_H */


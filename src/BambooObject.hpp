/*
 * File:   BambooObject.hpp
 * Author: jamie
 *
 * Created on 06 January 2012, 01:35
*/

#ifndef BAMBOOOBJECT_H
#define	BAMBOOOBJECT_H

#include "Object.hpp"

class BambooObject : public Object
{
public:
    virtual void isInside(Entity*);
    virtual void update(){}

    BambooObject( Vector const& pos );
    virtual ~BambooObject();
private:

};

#endif	/* BAMBOOOBJECT_H */


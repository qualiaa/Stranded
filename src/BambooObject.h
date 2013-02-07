/* 
 * File:   BambooObject.h
 * Author: jamie
 *
 * Created on 06 January 2012, 01:35
 */

#ifndef BAMBOOOBJECT_H
#define	BAMBOOOBJECT_H

#include "Object.h"

class BambooObject : public Object
{
public:
    virtual void IsInside(Entity*);
    
    BambooObject(float x, float y, GameState* state);
    virtual ~BambooObject();
private:

};

#endif	/* BAMBOOOBJECT_H */


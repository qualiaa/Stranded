/* 
 * File:   LargeRockObject.h
 * Author: jamie
 *
 * Created on 11 January 2012, 14:52
 */

#ifndef LARGEROCKOBJECT_H
#define	LARGEROCKOBJECT_H

#include "Object.h"

class LargeRockObject : public Object
{
public:
    LargeRockObject(float x, float y, GameState* parentState);
    virtual ~LargeRockObject();
private:

};

#endif	/* LARGEROCKOBJECT_H */


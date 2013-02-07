/* 
 * File:   SmallRockObject.h
 * Author: jamie
 *
 * Created on 11 January 2012, 15:21
 */

#ifndef SMALLROCKOBJECT_H
#define	SMALLROCKOBJECT_H

#include "Object.h"

class SmallRockObject : public Object
{
public:
    SmallRockObject(float x, float y, GameState* state);
    virtual ~SmallRockObject();
private:

};

#endif	/* SMALLROCKOBJECT_H */


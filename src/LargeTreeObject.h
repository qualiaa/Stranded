/* 
 * File:   LargeTreeObject.h
 * Author: jamie
 *
 * Created on 05 January 2012, 23:35
 */

#ifndef LARGETREEOBJECT_H
#define	LARGETREEOBJECT_H

#include "Object.h"

class LargeTreeObject: public Object
{
public:
    LargeTreeObject(float x, float y,GameState* state);
    virtual ~LargeTreeObject();
private:

};

#endif	/* LARGETREEOBJECT_H */


/* 
 * File:   SmallTreeObject.h
 * Author: jamie
 *
 * Created on 05 January 2012, 23:28
 */

#ifndef SMALLTREEOBJECT_H
#define	SMALLTREEOBJECT_H

#include "Object.h"

class SmallTreeObject : public Object
{
public:
    SmallTreeObject(float x, float y,GameState* state);
    virtual ~SmallTreeObject();
private:

};

#endif	/* SMALLTREEOBJECT_H */


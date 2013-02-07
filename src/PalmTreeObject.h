/* 
 * File:   PalmTreeObject.h
 * Author: jamie
 *
 * Created on 06 January 2012, 01:26
 */

#ifndef PALMTREEOBJECT_H
#define	PALMTREEOBJECT_H

#include "Object.h"

class PalmTreeObject : public Object
{
public:
    PalmTreeObject(float x, float y, GameState* state);
    virtual ~PalmTreeObject();
private:

};

#endif	/* PALMTREEOBJECT_H */


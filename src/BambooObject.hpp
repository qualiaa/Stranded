/*
 * File:   BambooObject.hpp
 * Author: jamie
 *
 * Created on 06 January 2012, 01:35
*/

#ifndef BAMBOOOBJECT_H
#define	BAMBOOOBJECT_H

#include "Engine/Graphics/Animation.hpp"
#include "Object.hpp"

class BambooObject : public Object
{
public:
    virtual void update();
    virtual void draw(IRender*);

    BambooObject(Vectorf const& pos);
private:
    Animation _anim; 
};

#endif	/* BAMBOOOBJECT_H */


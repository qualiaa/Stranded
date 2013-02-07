/* 
 * File:   Object.h
 * Author: jamie
 *
 * Created on 22 December 2011, 05:09
 */

#ifndef OBJECT_H
#define	OBJECT_H

#include "Entity.h"

class Object : public Entity
{
public:
    virtual void HandleInput(SDL_KeyboardEvent*) {}
    virtual void Update() {}
    
    virtual void IsInside(Entity*) {}
    
    Object(float x, float y, GameState* state, EntityType, Rotation);
    virtual ~Object();
protected:
};

#endif	/* OBJECT_H */


#pragma once
#ifndef OBJECT_H
#define	OBJECT_H

#include "Engine/Entity.hpp"
#include <string>

class Object : public Entity
{
public:
    virtual void update() {}
    
    virtual void isInside(Entity*) {}
    
    Object( Vector const& pos, char const* texture );
    virtual ~Object();
protected:
};

#endif


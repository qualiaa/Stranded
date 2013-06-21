#pragma once
#ifndef OBJECT_H
#define	OBJECT_H

#include "Engine/System/Entity.hpp"
#include <string>

class Object : public tank::Entity
{
public:
    virtual void update() {}

    Object(tank::Vectorf const& pos, char const* texture);
    virtual ~Object();
protected:
};

#endif


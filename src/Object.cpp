#include "Object.hpp"

#include <cstring>
#include "Engine/System/ServiceLocator.hpp"

//TODO Improve this
Object::Object(Vectorf const& pos, char const* texture)
:Entity( pos )
{
    if( strcmp( texture, "" ) )
    {
        setTexture(tank::ServiceLocator::getRender()->getTexture( texture ));
    }
}

Object::~Object()
{
}

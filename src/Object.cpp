#include "Object.hpp"

#include <cstring>
#include "Engine/System/ServiceLocator.hpp"

//TODO Improve this
Object::Object(Vectorf const& pos, char const* texture)
:Entity( pos )
{
    if( strcmp( texture, "" ) )
    {
        _texture = ServiceLocator::getRender()->getTexture( texture );
    }
}

Object::~Object() 
{
} 

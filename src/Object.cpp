#include "Object.hpp"

#include <iostream>

#include <cstring>
#include "Engine/ServiceLocator.hpp"

//TODO Improve this
Object::Object( Vector const& pos, char const* texture )
:Entity( pos )
{
    if( strcmp( texture, "" ) )
    {
        _texture = ServiceLocator::getRender()->getTexture( texture );
    }
    std::cout << "In object: " << _pos.x << ", " << _pos.y << std::endl;
}

Object::~Object() 
{
} 

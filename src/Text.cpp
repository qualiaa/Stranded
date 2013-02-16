#include "Text.hpp"

#include <iostream>

Text::Text(Vector const& pos, std::string const& pText )
:Entity( pos )
{
}

Text::~Text()
{
}

void Text::draw(IRender *const render)
{
    //Render::Instance()->DrawSurface(_text,_pos);
    //TODO Make this work properly
    render->drawText( _text.c_str(), _pos );
}

void Text::isInside(Entity *ent)
{

}

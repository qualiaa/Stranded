#include "Text.h"
#include <iostream>

Text::Text(float x, float y, GameState* state, EntityType entType, std::string &pText):Entity(x,y,state,entType)
{
    _text = Render::Instance()->GenerateText(entType, pText);
}

Text::~Text()
{
    std::cout <<"Text destructor called"<<std::endl;
    SDL_FreeSurface(_text);
}

void Text::Draw()
{
    Render::Instance()->DrawSurface(_text,_pos);
}

void Text::IsInside(Entity *ent)
{
    
}

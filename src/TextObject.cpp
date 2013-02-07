#include "TextObject.h"
#include <iostream>

TextObject::TextObject(float x, float y, GameState* state, EntityType entType, char const* cText, 
        Uint32 duration): Entity(x,y, state, entType, ROT_NONE)
{
    _text = NULL;
    std::string sText(cText);
    _displayTimer.Start();
    _text = new Text(x,y, state, entType,sText);
    _duration = duration;
}

TextObject::~TextObject()
{
    std::cout <<"TextObject destructor called"<< std::endl;
    delete _text;
}

void TextObject::SetText(char* cText)
{
	std::string sText(cText);
	if (_text != NULL)
	{
		delete _text;
	}
	_text = new Text(_pos.x,_pos.y,_state, _entType,sText);
}

void TextObject::HandleInput(SDL_KeyboardEvent* ke)
{
}

void TextObject::Update()
{
    if(_duration != 0 && _displayTimer.GetTicks() >= _duration)
    {
        Destroy();
    }
}

void TextObject::Draw()
{
    _text->Draw();
}

/* 
 * File:   TextObject.h
 * Author: jamie
 *
 * Created on 18 December 2011, 01:43
 */

#ifndef TEXTOBJECT_H
#define	TEXTOBJECT_H

#include "Entity.h"
#include "Vector.h"
#include "Timer.h"
#include "Text.h"

enum TextBox
{
    NONE,
    MAIN,
    OTHER
};

class GameState;

class TextObject : public Entity
{
public:
    void HandleInput(SDL_KeyboardEvent*);
    void Update();
    void Draw();

    TextObject(float x, float y, GameState* state, EntityType, char const* cText, Uint32 duration = 0);
    void SetText(char* cText);

    void IsInside(Entity*) {}

    ~TextObject();
private:
    Uint32 _duration;
    Timer _displayTimer;
    TextBox _textBox;
    Text* _text;
};


#endif	/* TEXTOBJECT_H */

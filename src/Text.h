/* 
 * File:   Text.h
 * Author: jamie
 *
 * Created on 18 December 2011, 02:29
 */

#ifndef TEXT_H
#define	TEXT_H

#include <SDL/SDL.h>
#include <string>
#include "Entity.h"

class Text : public Entity
{
public:
    void HandleInput(SDL_KeyboardEvent*) {}
    void Update() {}
    void Draw();
    
    void IsInside(Entity*);
    
    Text(float x, float y, GameState* state, EntityType, std::string &pText);
    ~Text();
private:
    SDL_Surface* _text;
};


#endif	/* TEXT_H */


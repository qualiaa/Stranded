/* 
 * File:   Render.h
 * Author: jamie
 *
 * Created on 17 December 2011, 05:34
 */

#ifndef RENDER_H
#define	RENDER_H

#include <SDL/SDL.h>
#include <string>
#include <map>
#include "Vector.h"
#include "Enums.h"

class Render
{
public:
    int Initialize();
    
    void DrawEntity(EntityType,Vector const& offset, Rotation rot, int frame = 0, int height = 1, int width = 1);
    void DrawSurface(SDL_Surface*,Vector &offset);
    
    void UpdateDisplay();
    
    SDL_Surface* GenerateText(EntityType, std::string &pText);
    
    static Render* Instance();
    ~Render();
private:
    SDL_Surface *_screen;
    std::map<EntityType,SDL_Surface*> _textures;
    
    
    SDL_Surface* LoadImage(const std::string filepath);
    
    int LoadTextures();
    
    static Render* _instance;
    Render();
};


#endif	/* RENDER_H */


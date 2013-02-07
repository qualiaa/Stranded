#include "Render.h"

#include <iostream>
#include <SDL/SDL_image.h>
#include <cstring>

Render::Render()
{
    _screen = NULL;
}
Render::~Render()
{
    std::cout << "Render engine shutting down" << std::endl;
    
    std::map<EntityType,SDL_Surface*>::iterator iter;
    for(iter = _textures.begin(); iter != _textures.end(); iter++)
    {
        SDL_FreeSurface(iter->second);
    }
    
    _textures.clear();
}

int Render::Initialize()
{
    std::cout << "Loading rendering engine" << std::endl;
    
    _screen = SDL_GetVideoSurface();
    if (_screen == NULL)
    {
        std::cout << "Something went awry: " << SDL_GetError() << std::endl;
        return 0;
    }
    
    if(LoadTextures() == 0)
    {
        std::cout << "Texture loading failed." << std::endl;
        return 0;
    }
    
    return 1;
}

int Render::LoadTextures()
{
    _textures[ENT_TEXT_BIG]    = LoadImage(   "Font.png"          );
    _textures[ENT_TEXT_SMALL]  = LoadImage(   "FontSmall.png"     );
    _textures[TILE_GRASS]      = LoadImage(   "GrassTiles.png"    );
    _textures[TILE_SAND]       = LoadImage(   "SandTiles.png"     );
    _textures[TILE_SAND_WATER] = LoadImage(   "SandWaterTiles.png");
    _textures[TILE_WATER]      = LoadImage(   "WaterTiles.png"    );
    _textures[ENT_PLAYER]      = LoadImage(   "Player.png"        );
    _textures[ENT_TREE_SMALL]  = LoadImage(   "SmallTree.png"     );
    _textures[ENT_TREE_LARGE]  = LoadImage(   "LargeTree.png"     );
    _textures[ENT_OCEAN_ROCK]  = LoadImage(   "OceanRock.png"     );
    _textures[ENT_BAMBOO]      = LoadImage(   "Bamboo.png"        );
    _textures[ENT_TREE_PALM]   = LoadImage(   "PalmTree.png"      );
    _textures[ENT_ROCK_SMALL]  = LoadImage(   "SmallRock.png"     );
    _textures[ENT_ROCK_LARGE]  = LoadImage(   "LargeRock.png"     );
    
    std::map<EntityType,SDL_Surface*>::iterator iter;
    
    for (iter = _textures.begin(); iter != _textures.end(); iter++)
    {
        if(iter->second == NULL)
        {
            return 0;
        }
    }
    return 1;
}

void Render::DrawEntity(EntityType entType, Vector const& pos, Rotation rot,
        int frame, int height, int width)
{
    SDL_Rect clip;
    SDL_Rect offset;

    clip.w = TILE_SIZE*width;
    clip.h = TILE_SIZE*height;
    clip.x = TILE_SIZE*rot;
    clip.y = TILE_SIZE*frame;

    offset.x = pos.x;
    offset.y = pos.y;
    
    SDL_BlitSurface(_textures[entType], &clip,_screen,&offset);
}

void Render::DrawSurface(SDL_Surface* surface, Vector &pos)
{
    SDL_Rect offset;
    offset.x = pos.x;
    offset.y = pos.y;
    
    SDL_BlitSurface(surface, NULL,_screen,&offset);
}

SDL_Surface* Render::LoadImage(const std::string fileName)
{
    SDL_Surface *temp = NULL;
    SDL_Surface *optimized = NULL;
    
    static std::string folder = "res/";
    std::string path = folder + fileName;
    
    temp = IMG_Load((path.c_str()));
    if(temp == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return NULL;
    }
    
    optimized = SDL_DisplayFormatAlpha(temp);
    
    SDL_FreeSurface(temp);
    
    return optimized;
}

SDL_Surface* Render::GenerateText(EntityType entType, std::string &text)
{
    SDL_Surface* font = _textures[entType];
    char c;
    int length = text.length();
    int maxWidth = 600;
    int letterSize = font->h;
    int width = length*letterSize;
    int height = ceil((float)width/maxWidth)*letterSize;
    
    if(width > maxWidth) { 
    width = maxWidth; }
    
    SDL_Surface *surface = SDL_CreateRGBSurface(SDL_SWSURFACE,
            width, height, 32,font->format->Rmask,font->format->Gmask,font->format->Bmask,font->format->Amask);
    
    SDL_Rect srcRect;
    SDL_Rect destRect;
    
    srcRect.w = letterSize;
    srcRect.h = letterSize;
    srcRect.x = 0;
    srcRect.y = 0;
    
    destRect.x = 0;
    destRect.y = 0;
    
    SDL_SetAlpha(font, 0, font->format->alpha);
    SDL_SetAlpha(surface,0, surface->format->alpha);
    
    for(int i = 0; i < length; i++)
    {
        c = toupper(text[i]);
        
        srcRect.x = ((int)c-32)*letterSize;
        
        SDL_BlitSurface(font, &srcRect, surface, &destRect);
        
        destRect.x += letterSize;
        
        if(destRect.x > maxWidth - letterSize)
        {
            destRect.x = 0;
            destRect.y += letterSize;
        }
    }
    
    SDL_SetAlpha(font, SDL_SRCALPHA, font->format->alpha);
    SDL_SetAlpha(surface,SDL_SRCALPHA, surface->format->alpha);
    
    return surface;
}

void Render::UpdateDisplay()
{    
    SDL_Flip(_screen);
    SDL_FillRect(_screen, NULL, SDL_MapRGBA(_screen->format,0x66,0xFF,0xFF,0xFF));
}

Render *Render::_instance = NULL;

Render *Render::Instance()
{
    if(_instance == NULL)
    {
        _instance = new Render;
    }
    return _instance;
}

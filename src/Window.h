/* 
 * File:   Window.h
 * Author: jamie
 *
 * Created on 17 December 2011, 05:14
 */

#ifndef WINDOW_H
#define	WINDOW_H

#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class Window
{
public:
    int Initialize();
    
    static Window* Instance();
    ~Window();
private:
    static Window* _instance;
    Window();
};


#endif	/* WINDOW_H */


#pragma once
#ifndef ANIMATION_H
#define ANIMATION_H

#include <string>
#include <vector>
#include "IRender.hpp"
#include "Rect.hpp"
#include "Vector.hpp"
#include "Texture.hpp"
#include "Timer.hpp"

class Animation
{
public:
    void add     ( char const* name, std::initializer_list<int> frames, unsigned int frameTime);
    void remove  ( char const* name );
    void play    ( char const* name, bool loop = true, void (*callback)() = NULL );
    void pause   ();
    void resume  ();
    void stop    ();
    void update  ();
    void draw    ( IRender *const, Vector const& pos );

    void setTexture( Texture const*const );
    //Constructor and Destructor
    Animation();
    Animation( Texture const*const t, Vector const& frameDims );
    ~Animation() {}
private:
    struct Anim
    {
        std::string                name;
        std::initializer_list<int> animation;
        unsigned int               time;
    };

    Texture      const* _texture;
    Anim         const* _currentAnim;
    unsigned int        _currentFrame;
    Timer               _animTimer;
    unsigned int        _frameTime;
    bool                _loop;
    Vector              _frameDimensions;
    void                ( *_callback )();

    Rect                _clip;

    std::vector<Anim>  _animations;

};
#endif

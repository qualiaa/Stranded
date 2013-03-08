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
    void add   ( char const* name, std::initializer_list<int> frames, unsigned int frameTime);
    void remove( char const* name );
    void draw  ( IRender *const, Vector const& pos );
    void play  ( char const* name, bool loop = true, void (*callback)() = NULL );
    void pause ();
    void resume();
    void stop  ();
    void update();
    
    bool playing() { return _currentAnimation; }
    std::string currentAnimation() { return _currentAnimation->name; }

    void setTexture( Texture const*const );
    //Constructor and Destructor
    Animation();
    Animation( Texture const*const t, Vector const& frameDims );
    ~Animation() {}
private:
    struct AnimationInfo
    {
        std::string      name;
        std::vector<int> frameList;          //TODO Find out if this is evil
        unsigned int     time;
    };

    Texture       const* _texture;
    AnimationInfo*       _currentAnimation;
    unsigned int         _currentFrame;
    Timer                _animTimer;
    bool                 _loop;
    Vector               _frameDimensions;
    void                 ( *_callback )();

    Rect                 _clip;

    std::vector<AnimationInfo>  _animations;
};
#endif

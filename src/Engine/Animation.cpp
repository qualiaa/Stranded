#include "Animation.hpp"

#include <algorithm>
#include <iostream>

Animation::Animation()
: _texture ( NULL ),
  _currentAnim( NULL ),
  _currentFrame( 0 ),
  _frameTime( 0 ),
  _loop( false ),
  _frameDimensions( {0, 0} ),
  _callback( NULL ),
  _clip( { 0, 0, 0, 0 } ) {}

Animation::Animation( Texture const* t, Vector const& frameDims )
: _texture( t ),
  _currentAnim( NULL ),
  _currentFrame( 0 ),
  _frameTime( 0 ),
  _loop( false ),
  _frameDimensions( frameDims ),
  _callback( NULL ),
  _clip( { 0, 0, ( int )frameDims.x, ( int )frameDims.y } ) { }

void Animation::add( char const* name,
                     std::initializer_list<int> frames,
                     unsigned int time )
{
    std::string strName = name;
    std::cout << "Creating new animation:" << std::endl;
    std::cout << "name: " << name << std::endl;
    std::cout << "frameTime: " << time << std::endl;
    std::cout << "frames: ";
    for( auto i : frames )
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
    _animations.push_back( { strName, frames, time } );
}

void Animation::remove( char const* name )
{
    std::string strName = name;
    // Find the animation
    std::vector<Anim>::iterator iter =
        std::find_if( _animations.begin(),
                      _animations.end(),
                      [strName]( Anim anim )->bool
                      { return anim.name == strName; } );

    if( iter != _animations.end() )
    {
        _animations.erase( iter );
    }
}

void Animation::play( char const* name, bool loop, void ( *callback )() )
{
    std::string strName = name;

    for( Anim anim : _animations )
    {
        if( anim.name == strName )
        {
            _currentAnim = &anim;
            _animTimer.start();
            std::cout << "Found anim: " << _currentAnim->name << std::endl;

            _loop = loop;
            _callback = callback;

            //This may be a bad idea?
            //Probably fine though
            update();
        }
    }
    std::cout << "done" << std::endl;
}

void Animation::pause()
{
    _animTimer.pause();
}

void Animation::resume()
{
    if( _animTimer.isPaused() && _currentAnim != NULL )
    {
        _animTimer.resume();
    }
}

void Animation::stop()
{
    _animTimer.stop();
    _currentAnim = NULL;
}

void Animation::update()
{
    if( _currentAnim )
    {
        if( _animTimer.getTicks() > _frameTime )
        {
            ++_currentFrame;
            _animTimer.start();

            if( _currentFrame >= _currentAnim->animation.size() );
            {
                _currentFrame = 0;

                if( _callback ) _callback();

                if ( !_loop )
                {
                    stop();
                }
            }
        }
    }

    if( _currentAnim )
    { 
        std::cout << _currentAnim->name << std::endl;
        std::initializer_list<int>::iterator frameIter = _currentAnim->animation.begin();
        frameIter += _currentFrame;

        _clip.x = ( *frameIter ) * _frameDimensions.x;
        _clip.w = _clip.x        + _frameDimensions.x;
    }
}

void Animation::draw( IRender *const render, Vector const& pos )
{
    render->draw( _texture, pos, _clip );
}

void Animation::setTexture( Texture const*const texture  )
{
    _texture = texture;
}



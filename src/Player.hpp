#ifndef PLAYER_H
#define	PLAYER_H

#include "Engine/Graphics/Animation.hpp"
#include "Engine/System/Entity.hpp"

class MainState;

class Player : public Entity
{
public:
    void move(int rotation, bool moving);
    void update();
    virtual void draw( IRender *const );
    
    Player(Vectorf const& pos, MainState*);
private:
    void handleCollisions();
    Animation    _anim;
    unsigned int _rotation;
    Vectori      _mapPos;
    MainState*   _mState;

    Vectorf      _vel;
    Vectorf      _lastPos;
    float      _speed;
    void checkSides();
};
#endif

#ifndef PLAYER_H
#define	PLAYER_H

#include "Engine/Graphics/Animation.hpp"
#include "Mover.hpp"

class MainState;

class Player : public Mover
{
public:
    void move(int rotation, bool moving);
    void update();
    virtual void draw( IRender *const );
    
    void isInside(Entity *ent) {}
    
    Player(Vectorf const& pos, MainState*);
private:
    void handleCollisions();
    Animation    _anim;
    unsigned int _rotation;
    Rect         _lastHitBox;
    Vectori      _mapPos;
    MainState*   _mState;

    void checkSides();
};
#endif

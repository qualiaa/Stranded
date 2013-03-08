#ifndef PLAYER_H
#define	PLAYER_H

#include "Engine/Animation.hpp"
#include "Mover.hpp"

class MainState;

class Player : public Mover
{
public:
    void move(int rotation, bool moving);
    void update();
    virtual void draw( IRender *const );
    
    void isInside(Entity *ent);
    
    Player(Vector const& pos );
    ~Player();
private:
    Animation _anim;
    int _rotation;
    Rect _lastHitBox;
    Vector _mapPos;
    MainState* _mState;
    void checkSides();
};

#endif

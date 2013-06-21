#ifndef PLAYER_H
#define	PLAYER_H

#include "Engine/Graphics/Animation.hpp"
#include "Engine/System/Entity.hpp"

class MainState;

class Player : public tank::Entity
{
public:
    void move(int rotation, bool moving);
    void update();
    virtual void draw( tank::IRender *const );

    Player(Vectorf const& pos, MainState*);
private:
    void handleCollisions();
    tank::Animation    anim_;
    unsigned int rotation_;
    Vectori      mapPos_;
    MainState*   mState_;

    Vectorf      vel_;
    Vectorf      lastPos_;
    float      speed_;
    void checkSides();
};
#endif

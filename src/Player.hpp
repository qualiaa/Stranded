#ifndef PLAYER_HPP
#define	PLAYER_HPP

#include <Tank/Graphics/FrameList.hpp>
#include "Object.hpp"

class MainState;

class Player : public Object
{
public:
    void move(int rotation, bool moving);
    virtual void update() override;

    Player(tank::Vectorf pos, tank::observing_ptr<MainState>);
private:
    void handleCollisions();
    tank::observing_ptr<tank::FrameList> anim_;
    unsigned int rotation_;
    tank::Vectori mapPos_;
    tank::observing_ptr<MainState> mState_;

    tank::Vectorf vel_;
    tank::Vectorf lastPos_;
    float speed_;
    void checkSides();
};

#endif /* PLAYER_HPP */

#ifndef PLAYER_HPP
#define	PLAYER_HPP

#include <Tank/Graphics/FrameList.hpp>
#include <Tank/System/EventHandler.hpp>
#include "Object.hpp"

class MainWorld;

class Player : public Object
{
    tank::observing_ptr<MainWorld> mState_;
    tank::observing_ptr<tank::FrameList> anim_;
    float speed_ {5};
    unsigned int rotation_ {1};
    tank::Vectorf vel_ {};
    tank::Vectorf lastPos_ {};
    tank::Vectori mapPos_ {};
    std::unique_ptr<tank::EventHandler::Connection> a, up, right, down, left;

public:

    virtual void update() override;

    Player(tank::Vectorf pos, tank::observing_ptr<MainWorld>);

private:
    void handleCollisions();
    void checkSides();
};

#endif /* PLAYER_HPP */

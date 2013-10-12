#ifndef PLAYER_HPP
#define	PLAYER_HPP

#include <Tank/Graphics/FrameList.hpp>
#include <Tank/System/EventHandler.hpp>
#include "Object.hpp"

class MainState;

class Player : public Object
{
public:
    std::unique_ptr<tank::EventHandler::Connection> upCon;
    std::unique_ptr<tank::EventHandler::Connection> rightCon;
    std::unique_ptr<tank::EventHandler::Connection> downCon;
    std::unique_ptr<tank::EventHandler::Connection> leftCon;
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
public:
    void move(int rotation, bool moving);
    virtual void update() override;

    Player(tank::Vectorf pos, tank::observing_ptr<MainState>);

    virtual void onAdded() override;

};

#endif /* PLAYER_HPP */

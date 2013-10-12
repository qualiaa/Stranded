#ifndef MAINSTATE_H
#define	MAINSTATE_H

#include <Tank/System/State.hpp>
#include <Tank/Utility/Vector.hpp>
#include <Tank/Graphics/Image.hpp>

class Player;
class Room;

class MainState : public tank::State
{
public:
    //Images
    static tank::Image font;
    static tank::Image fontsmall;
    static tank::Image grass;
    static tank::Image sand;
    static tank::Image sandwater;
    static tank::Image water;
    static tank::Image player;
    static tank::Image smalltree;
    static tank::Image largetree;
    static tank::Image oceanrock;
    static tank::Image bamboo;
    static tank::Image palmtree;
    static tank::Image smallrock;
    static tank::Image largerock;

    void changeRoom(tank::Vectori coords);

    const tank::observing_ptr<Room> currentRoom();

    virtual void update() override;
    virtual void draw() override;

    MainState();
    virtual ~MainState();
private:
    std::vector<std::unique_ptr<Room>> rooms_;

    tank::observing_ptr<Room>   currentRoom_;
    tank::observing_ptr<Player> player_;
    bool    paused_;

    void loadRooms();
    void pause();

    MainState           (MainState const&);
    MainState& operator=(MainState const&);
};
#endif

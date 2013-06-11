#ifndef MAINSTATE_H
#define	MAINSTATE_H

#include "Engine/System/State.hpp"

class Player;
class Room;

class MainState : public State
{
public:
    void     changeRoom(Vectori const& coords);

    Room const*      currentRoom();

    virtual void     handleEvents(SDL_KeyboardEvent *const);
    virtual void     draw(IRender*);

    virtual bool     initialize();

    MainState();
    virtual ~MainState();
private:
    std::vector<Room*> rooms_;

    Room*   currentRoom_;
    Player* player_;
    bool    paused_;

    void checkCollisions(Entity*,Entity*);
    bool loadRooms();
    void pause();

    MainState           (MainState const&);
    MainState& operator=(MainState const&);
};
#endif

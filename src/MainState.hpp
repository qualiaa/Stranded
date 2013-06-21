#ifndef MAINSTATE_H
#define	MAINSTATE_H

#include "Engine/System/State.hpp"

class Player;
class Room;

class MainState : public tank::State
{
public:
    void     changeRoom(tank::Vectori const& coords);

    Room const* currentRoom();

    virtual void handleEvents(SDL_KeyboardEvent *const) override;
    virtual void update() override;
    virtual void draw(tank::IRender*) override;

    MainState();
    virtual ~MainState();
private:
    std::vector<Room*> rooms_;

    Room*   currentRoom_;
    Player* player_;
    bool    paused_;

    void checkCollisions(tank::Entity*,tank::Entity*);
    void loadRooms();
    void pause();

    MainState           (MainState const&);
    MainState& operator=(MainState const&);
};
#endif

#ifndef MAINSTATE_H
#define	MAINSTATE_H

#include "Engine/GameState.hpp"

class Player;
class Room;

class MainState : public GameState
{
public:
    void     changeRoom(Vector const& coords);
    
    Room const*      currentRoom();
    
    virtual void     handleEvents(SDL_KeyboardEvent *const);
    virtual void     update();
    virtual void     draw(IRender *const);
    
    virtual bool     initialize();
    
    MainState();
    virtual ~MainState();
private:
    std::vector<Room*> _rooms;

    Room*              _currentRoom;
    Player*            _player;
    bool               _paused;
    
    void checkCollisions(Entity*,Entity*);
    bool loadRooms();
    void pause();

    MainState           (MainState const&);
    MainState& operator=(MainState const&);
}; 
#endif

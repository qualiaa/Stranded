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
    
    void     handleEvents(SDL_KeyboardEvent *const);
    void     update();
    void     draw(IRender *const);
    
    bool     initialize();
    
    MainState();
    ~MainState();
private:
    std::vector<Room*> _rooms;

    Room*              _currentRoom;
    Player*            _player;
    bool               _paused;
    
    void checkCollisions(Entity*,Entity*);
    bool loadRooms();
    void pause();
}; 
#endif

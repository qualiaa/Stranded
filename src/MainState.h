/* 
 * File:   MainState.h
 * Author: jamie
 *
 * Created on 25 December 2011, 07:50
 */

#ifndef MAINSTATE_H
#define	MAINSTATE_H

#include "GameState.h"
#include "Room.h"
#include "Player.h"

class Player;
class Room;

class MainState : public GameState
{
public:
    virtual void ChangeRoom(Vector coords);
    
    Room const* const CurrentRoom();
    
    virtual void HandleEvents(SDL_KeyboardEvent*);
    virtual void Update();
    virtual void Draw();
    
    virtual int Load();
    
    MainState();
    virtual ~MainState();
private:
    std::vector<Room*> _rooms;
    Room *_currentRoom;
    Player *_player;
    bool _paused;
    
    void CheckCollisions(Entity*,Entity*);
    int LoadRooms();
    void Pause();
};

#endif	/* MAINSTATE_H */


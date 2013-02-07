/*
 * File:   Player.h
 * Author: jamie
 *
 * Created on 17 December 2011, 20:39
 */

#ifndef PLAYER_H
#define	PLAYER_H

#include "Mover.h"
#include "MainState.h"
#include "Room.h"
#include "Vector.h"
#include "TextObject.h"

class MainState;

class Player : public Mover
{
public:
    void Move(Rotation, bool moving);
    void Update();
    
    void IsInside(Entity *ent);

    Player(float x, float y, MainState* state);
    ~Player();
private:
    SDL_Rect _lastHitBox;
    MainState* _mState;
    void CheckSides();
};

#endif	/* PLAYER_H */
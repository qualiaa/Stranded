/* 
 * File:   Entity.h
 * Author: jamie
 *
 * Created on 17 December 2011, 14:57
 */

#ifndef ENTITY_H
#define	ENTITY_H

#include <SDL/SDL_events.h>
#include "GameState.h"
#include "Enums.h"
#include "Render.h"
#include "Vector.h"
#include "Timer.h"

class GameState;

class Entity
{
public:
    virtual void Update() = 0;
    virtual void Draw();
    
    void Hide();
    void Show();
    
    virtual void IsInside(Entity*) = 0;
    
    Vector GetPos() { return _pos; }
    SDL_Rect GetHitBox() { return _hitBox; }
    bool IsImpediment() { return _impediment; }
    EntityType GetEntType() { return _entType; }
    int GetY() { return _hitBox.y; }
    Rotation GetRotation() { return _rotation; }
    
    int GetActorID() { return _actorID; }
    static int GetNumEnts() { return _numEnts; }
    
    void Destroy();
    
    Entity(float x, float y,GameState* state, EntityType = NULL_ENTITY, Rotation = ROT_NONE);
    virtual ~Entity();
protected:
    static int _numEnts;
    int _actorID;
	
    Vector _pos;
    SDL_Rect _hitBox;
    int _texHeight;
    int _texWidth;
    GameState* _state;

    Rotation _rotation;
    EntityType _entType;

    Timer _animTimer;
    Uint32 _animTime;
    int _frame;
    int _numFrames;

    Vector _mapPos;

    bool _impediment;
    bool _display;
    
    void Animate();
};


#endif	/* ENTITY_H */


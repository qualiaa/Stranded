#pragma once
#ifndef ENTITY_H
#define	ENTITY_H

#include "IRender.hpp"
#include "Vector.hpp"
#include "Texture.hpp"
#include "Rect.hpp"

class GameState;

class Entity
{
public: 
    virtual void update() = 0;
    virtual void draw( IRender *const );

    //TODO Replace with FP-style collide( "type" )
    virtual void isInside(Entity*) = 0;
    
    //Getters
    Vector   const& getPos()      const { return _pos;     } 
    Rect     const& getHitBox()   const { return _hitBox;  } 
    bool            isSolid()     const { return _solid;   } 

    int             getActorID()  const { return _actorID; } 
    static int      getNumEnts()        { return _numEnts; } 

    //Setters
    void setState( GameState      *const state );
    void setPos  ( Vector    const&      pos );

    /* ------------------------------ *
     * Constructor and Destructor
     * ------------------------------ */
    Entity( Vector const& pos );
    virtual ~Entity();
protected:
    static int _numEnts;
           int _actorID;
 
    Vector            _pos;
    Rect              _hitBox;
    Texture    const* _texture;
    GameState*        _state;

    bool              _solid;
    bool              _visible; 
};


#endif 

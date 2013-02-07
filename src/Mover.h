/* 
 * File:   Mover.h
 * Author: jamie
 *
 * Created on 17 December 2011, 18:12
 */

#ifndef MOVER_H
#define	MOVER_H

#include "Entity.h"
#include "Vector.h"

class Mover : public Entity
{
public:
    virtual void Update();
    
    Mover(float x, float y, GameState* state, EntityType entType, Rotation rot = ROT_NONE);
    virtual ~Mover();
protected:
    Vector _lastPos;
    Vector _vel;
    //Vector _acc;
    
    float _speed;
    bool _movingX;
    bool _movingY;

    void Move1();
    void Move2();
};

#endif	/* MOVER_H */


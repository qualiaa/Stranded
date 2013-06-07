/* 
 * File:   Mover.hpp
 * Author: jamie
 *
 * Created on 17 December 2011, 18:12
 */

#ifndef MOVER_H
#define	MOVER_H

#include "Engine/System/Entity.hpp"

class Mover : public Entity
{
public:
    virtual void update();
    
    Mover(Vectorf const& pos);
    virtual ~Mover();
protected:
    Vectorf _lastPos;
    Vectorf _vel;
    //Vectorf _acc;
    
    float _speed;
    bool _movingX;
    bool _movingY;

    void move1();
    void move2();
};

#endif	/* MOVER_H */


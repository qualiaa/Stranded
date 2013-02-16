/* 
 * File:   SmallRockObject.hpp
 * Author: jamie
 *
 * Created on 11 January 2012, 15:21
 */

#ifndef SMALLROCKOBJECT_H
#define	SMALLROCKOBJECT_H

#include "Object.hpp"

class SmallRockObject : public Entity
{
public:
    virtual void isInside( Entity* ){}
    virtual void update(){}
    SmallRockObject(Vector const& pos );
    virtual ~SmallRockObject();
private:

};

#endif	/* SMALLROCKOBJECT_H */


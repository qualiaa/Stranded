/* 
 * File:   LargeRockObject.hpp
 * Author: jamie
 *
 * Created on 11 January 2012, 14:52
 */

#ifndef LARGEROCKOBJECT_H
#define	LARGEROCKOBJECT_H

#include "Object.hpp"

class LargeRockObject : public Entity
{
public:
    virtual void isInside( Entity* ){}
    virtual void update(){}
    LargeRockObject( Vector const& pos );
    virtual ~LargeRockObject();
private:

};

#endif	/* LARGEROCKOBJECT_H */


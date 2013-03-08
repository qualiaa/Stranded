/* 
 * File:   LargeTreeObject.hpp
 * Author: jamie
 *
 * Created on 05 January 2012, 23:35
 */

#ifndef LARGETREEOBJECT_H
#define	LARGETREEOBJECT_H

#include "Object.hpp"

class LargeTreeObject: public Entity
{
public:
    virtual void isInside( Entity* ){}
    virtual void update(){}
    LargeTreeObject( Vector const& pos );
    virtual ~LargeTreeObject();
private:

};

#endif	/* LARGETREEOBJECT_H */

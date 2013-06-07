/* 
 * File:   SmallTreeObject.hpp
 * Author: jamie
 *
 * Created on 05 January 2012, 23:28
 */

#ifndef SMALLTREEOBJECT_H
#define	SMALLTREEOBJECT_H

#include "Object.hpp"

class SmallTreeObject : public Object
{
public:
    virtual void isInside( Entity* ){}
    virtual void update(){}
    SmallTreeObject( Vectorf const& pos );
    virtual ~SmallTreeObject();
private:

};

#endif	/* SMALLTREEOBJECT_H */


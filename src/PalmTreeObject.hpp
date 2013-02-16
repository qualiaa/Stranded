#ifndef PALMTREEOBJECT_H
#define	PALMTREEOBJECT_H

#include "Object.hpp"

class PalmTreeObject : public Entity
{
public:
    virtual void update(){}
    virtual void isInside( Entity* ){}
    PalmTreeObject( Vector const& pos );
    virtual ~PalmTreeObject();
private:

}; 
#endif 

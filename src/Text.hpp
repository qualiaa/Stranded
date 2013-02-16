#ifndef TEXT_H
#define	TEXT_H

#include "Engine/Entity.hpp"

#include <string>

class Text : public Entity
{
public:
    void update() {}
    void draw(IRender *const);
    
    void isInside(Entity*);
    
    Text( Vector const&, std::string const& pText );
    ~Text();
private:
    std::string _text;
}; 
#endif

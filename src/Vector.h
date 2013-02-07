/* 
 * File:   Vector.h
 * Author: jamie
 *
 * Explain the concept of vectors for stupid computers.
 * 
 * Created on 17 December 2011, 04:27
 */

#ifndef VECTOR_H
#define	VECTOR_H

#include <cmath>

struct Vector
{
    float x, y;
    
    Vector():x(0),y(0) {}
    Vector(float x, float y):x(x),y(y) {}
    
    float Magnitude()
    {
        return sqrt(x*x+y*y);
    }
    
    Vector Versor()
    {
        return Vector(x/Magnitude(),y/Magnitude());
    }
    
    float operator*(Vector &vect){
        return x*vect.x + y*vect.y;}
    Vector operator*(float f){
        return Vector(x*f,y*f);}
    
    Vector operator+(Vector &vect){
        return Vector(x+vect.x, y+vect.y);}
    Vector operator+(float f){
        return Vector(x+f, y+f);}
    
    Vector operator-(Vector &vect){
        return Vector(x-vect.x,y-vect.y);}
    Vector operator-(float f){
        return Vector(x-f,y-f);}
    
    Vector &operator*=(float f)
    {
        x *= f;
        y *= f;
        
        return *this;
    }
    
    Vector &operator+=(Vector &vect)
    {
        x += vect.x;
        y += vect.y;
        
        return *this;
    }
    
    Vector &operator+=(float f)
    {
        x += f;
        y += f;
        
        return *this;
    }
    
    Vector &operator-=(Vector &vect)
    {
        x -= vect.x;
        y -= vect.y;
        
        return *this;
    }
    
    Vector &operator-=(float f)
    {
        x -= f;
        y -= f;
        
        return *this;
    }
    
    bool operator==(const Vector &vect)
    {
        if(x == vect.x && y == vect.y)
        {
            return true;
        }
        return false;
    }
};



#endif	/* VECTOR_H */


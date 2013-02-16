#pragma once
#ifndef VECTOR_H
#define	VECTOR_H

#include <cmath>

struct Vector
{
    double x, y, z;
    
    double Magnitude()
    {
        return sqrt(x*x+y*y);
    }
    
    Vector Versor()
    {
        return { x/Magnitude(),y/Magnitude() };
    }
    
    float operator*(Vector &vect){
        return x*vect.x + y*vect.y;}
    Vector operator*(float f){
        return {x*f,y*f};}
    
    Vector operator+(Vector &vect){
        return {x+vect.x, y+vect.y};}
    Vector operator+(float f){
        return {x+f, y+f};}
    
    Vector operator-(Vector &vect){
        return {x-vect.x,y-vect.y};}
    Vector operator-(float f){
        return {x-f,y-f};}
    
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
#endif

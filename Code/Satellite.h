//
//  Satellite.h
//  G53GRA.Framework
//
//  Created by Jingxiao Ma on 2018/4/30.
//  Copyright © 2018年 w.o.c.ward. All rights reserved.
//

#ifndef Satellite_hpp
#define Satellite_hpp

#include <stdio.h>
#include "VectorMath.h"
#include "DisplayableObject.h"
#include "Animation.h"

class Satellite :
    public DisplayableObject,
    public Animation
{
public:
    Satellite(float _scale, float _x, float _y, float _z, float _animationTime);
    ~Satellite(){}
    void Display();
    void Update(const double& deltaTime);
    
private:
    void drawWing();
    void drawHead();
    void drawColumn(float radius, float height);
    float new_pos[3];
    float scale;
    float animationTime;
    
    float leftWingAngel = 0.f;  // Used for rotating left wing
    float rightWingAngel = 0.f; // Used for rotating right wing
    float satelliteRotation = 0.f;  // Used for satellite rotation
    
};


#endif /* Satellite_hpp */

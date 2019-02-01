//
//  Astronaut.h
//  G53GRA.Framework
//
//  Created by Jingxiao Ma on 2018/4/30.
//  Copyright © 2018年 w.o.c.ward. All rights reserved.
//

#ifndef Astronaut_hpp
#define Astronaut_hpp

#include <stdio.h>
#include "DisplayableObject.h"
#include "Animation.h"
#include "VectorMath.h"
#include "Input.h"

class Astronaut :
    public DisplayableObject,
    public Animation
{
public:
    Astronaut(float _scale, float _x, float _y, float _z, float _animationTime);
    ~Astronaut(){}
    
    void Display();
    void Update(const double& deltaTime);
    
private:
    void drawArm(float r1, float r2, bool isLeft);
    void drawLeg(float r);
    void drawHead();
    void drawColumn(float radius, float height);    // Draw a column based on radius and height
    
    float aT = 0;
    float animationTime;
    
    float scale = 1.f;
    float new_pos[3];
    float movement_y = 0.5f;
    float leftArm1 = -30.f;
    float leftArm2 = 80.f;
    float rightArm1 = 30.f;
    float rightArm2 = 10.f;
    float leftLeg = 20.f;
    float rightLeg = -20.f;
    
};

#endif /* Astronaut_hpp */

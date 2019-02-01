//
//  Earth.h
//  G53GRA.Framework
//
//  Created by Jingxiao Ma on 2018/4/30.
//  Copyright © 2018年 w.o.c.ward. All rights reserved.
//

#ifndef Earth_hpp
#define Earth_hpp

#include <stdio.h>
#include "DisplayableObject.h"
#include "Animation.h"

class Earth :
    public DisplayableObject,
    public Animation
{
public:
    Earth(float _radius, float _distance, float _rotationSpeed, float _revolutionSpeed, float _moon_radius, float _moon_distance, float _moon_rotationSpeed, float _moon_revolutionSpeed, GLuint _texid);
    ~Earth(){}
    void Display();
    void Update(const double& deltaTime);
    
private:
    GLuint texid;
    bool toTexture = false;
    float radius;
    float distanceFromSun;
    // Rotate around axis of itself
    float rotationAngle;
    float rotationSpeed;
    // Revolve around sun
    float revolutionAngle;
    float revolutionSpeed;
    
    // Information about moon
    float moonRadius;
    float moonDistance;
    // Rotate around axis of itself
    float moonRotationAngle;
    float moonRotationSpeed;
    // Moon revolves around earth
    float moonRevolutionAngle;
    float moonRevolutionSpeed;
};

#endif /* Earth_hpp */

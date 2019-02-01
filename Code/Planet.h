//
//  Planet.h
//  G53GRA.Framework
//
//  Created by Jingxiao Ma on 2018/4/30.
//  Copyright © 2018年 w.o.c.ward. All rights reserved.
//

#ifndef Planet_hpp
#define Planet_hpp

#include <stdio.h>
#include "DisplayableObject.h"
#include "Animation.h"

class Planet    :
    public DisplayableObject, public Animation
{
public:
    Planet(float _radius, float _distance, float _rotationSpeed, float _revolutionSpeed, GLuint _texid);
    ~Planet(){}
    void setCycleTexture(GLuint _texCycle);
    void Display();
    void Update(const double& deltaTime);
    
protected:
    GLuint texid;              // Texutre for the planet surface
    GLuint texCycle = NULL;    // Texture for the ring (of saturn)
    bool toTexture = false;
    float radius;
    float distanceFromSun;
    float rotationAngle;
    float rotationSpeed;
    float revolutionAngle;
    float revolutionSpeed;
};

#endif /* Planet_hpp */

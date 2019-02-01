//
//  Sun.h
//  G53GRA.Framework
//
//  Created by Jingxiao Ma on 2018/4/30.
//  Copyright © 2018年 w.o.c.ward. All rights reserved.
//

#ifndef Sun_hpp
#define Sun_hpp

#include <stdio.h>
#include "DisplayableObject.h"
#include "Animation.h"

class Sun   :
    public DisplayableObject,
    public Animation
{
public:
    Sun(float _radius, float _rotationSpeed, GLuint _texid);
    ~Sun(){}
    void Display();
    void Update(const double& deltaTime);

private:
    GLuint texid;
    bool toTexture = false;
    float rotationAngle;
    float radius;
    float rotationSpeed;
    
};

#endif /* Sun_hpp */

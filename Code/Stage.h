//
//  Stage.h
//  G53GRA.Framework
//
//  Created by Jingxiao Ma on 2018/4/30.
//  Copyright © 2018年 w.o.c.ward. All rights reserved.
//

#ifndef Stage_hpp
#define Stage_hpp

#include <stdio.h>
#include "DisplayableObject.h"

class Stage : public DisplayableObject
{
public:
    Stage(float _size, GLuint* _texid);
    ~Stage(){}
    void Display();

private:
    GLuint* texid;
    bool toTexture = false;
    float stageSize;
};




#endif /* Stage_hpp */

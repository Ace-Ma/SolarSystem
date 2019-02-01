//
//  Stage.cpp
//  G53GRA.Framework
//
//  Created by Jingxiao Ma on 2018/4/30.
//  Copyright © 2018年 w.o.c.ward. All rights reserved.
//

#include "Stage.h"

Stage::Stage(float _size, GLuint* _texid)
        : stageSize(_size)
{
    texid = _texid;
    if (_texid != NULL)
        toTexture = true;
}

void Stage::Display()
{
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glDisable(GL_LIGHTING);         // Disable lighting on skybox
    glColor4f(1.f, 1.f, 1.f, 1.f);  // Set fill to be invisible
    
    if(toTexture)   glEnable(GL_TEXTURE_2D);
    
    // Left side
    if(toTexture)   glBindTexture(GL_TEXTURE_2D, texid[0]);
    glBegin(GL_QUADS);
    if (toTexture)  glTexCoord2f(1.f, 1.f);
    glVertex3f(-stageSize, stageSize, -stageSize);
    if (toTexture)  glTexCoord2f(0.f, 1.f);
    glVertex3f(-stageSize, stageSize, stageSize);
    if (toTexture)  glTexCoord2f(0.f, 0.f);
    glVertex3f(-stageSize, -stageSize, stageSize);
    if (toTexture)  glTexCoord2f(1.f, 0.f);
    glVertex3f(-stageSize, -stageSize, -stageSize);
    glEnd();
    
    // Right side
    if(toTexture)   glBindTexture(GL_TEXTURE_2D, texid[1]);
    glBegin(GL_QUADS);
    if (toTexture)  glTexCoord2f(1.f, 1.f);
    glVertex3f(stageSize, stageSize, stageSize);
    if (toTexture)  glTexCoord2f(0.f, 1.f);
    glVertex3f(stageSize, stageSize, -stageSize);
    if (toTexture)  glTexCoord2f(0.f, 0.f);
    glVertex3f(stageSize, -stageSize, -stageSize);
    if (toTexture)  glTexCoord2f(1.f, 0.f);
    glVertex3f(stageSize, -stageSize, stageSize);
    glEnd();
    
    // Far side
    if (toTexture)  glBindTexture(GL_TEXTURE_2D, texid[2]);
    glBegin(GL_QUADS);
    if (toTexture)  glTexCoord2f(1.f, 1.f);
    glVertex3f(stageSize, stageSize, -stageSize);
    if (toTexture)  glTexCoord2f(0.f, 1.f);
    glVertex3f(-stageSize, stageSize, -stageSize);
    if (toTexture)  glTexCoord2f(0.f, 0.f);
    glVertex3f(-stageSize, -stageSize, -stageSize);
    if (toTexture)  glTexCoord2f(1.f, 0.f);
    glVertex3f(stageSize, -stageSize, -stageSize);
    glEnd();
    
    // Back side
    if (toTexture)  glBindTexture(GL_TEXTURE_2D, texid[3]);
    glBegin(GL_QUADS);
    if (toTexture)  glTexCoord2f(1.f, 1.f);
    glVertex3f(-stageSize, stageSize, stageSize);
    if (toTexture)  glTexCoord2f(0.f, 1.f);
    glVertex3f(stageSize, stageSize, stageSize);
    if (toTexture)  glTexCoord2f(0.f, 0.f);
    glVertex3f(stageSize, -stageSize, stageSize);
    if (toTexture)  glTexCoord2f(1.f, 0.f);
    glVertex3f(-stageSize, -stageSize, stageSize);
    glEnd();
    
    // Down side
    if (toTexture)  glBindTexture(GL_TEXTURE_2D, texid[4]);
    glBegin(GL_QUADS);
    if (toTexture)  glTexCoord2f(0.f, 0.f);
    glVertex3f(-stageSize, -stageSize, stageSize);
    if (toTexture)  glTexCoord2f(1.f, 0.f);
    glVertex3f(stageSize, -stageSize, stageSize);
    if (toTexture)  glTexCoord2f(1.f, 1.f);
    glVertex3f(stageSize, -stageSize, -stageSize);
    if (toTexture)  glTexCoord2f(0.f, 1.f);
    glVertex3f(-stageSize, -stageSize, -stageSize);
    glEnd();
    
    // Up side
    if (toTexture)  glBindTexture(GL_TEXTURE_2D, texid[5]);
    glBegin(GL_QUADS);
    if (toTexture)  glTexCoord2f(1.f, 1.f);
    glVertex3f(stageSize, stageSize, stageSize);
    if (toTexture)  glTexCoord2f(0.f, 1.f);
    glVertex3f(-stageSize, stageSize, stageSize);
    if (toTexture)  glTexCoord2f(0.f, 0.f);
    glVertex3f(-stageSize, stageSize, -stageSize);
    if (toTexture)  glTexCoord2f(1.f, 0.f);
    glVertex3f(stageSize, stageSize, -stageSize);
    glEnd();
    
    if (toTexture)  glDisable(GL_TEXTURE_2D);
    
    glEnable(GL_LIGHTING);
    glPopAttrib();
    glPopMatrix();
}

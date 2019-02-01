//
//  Sun.cpp
//  G53GRA.Framework
//
//  Created by Jingxiao Ma on 2018/4/30.
//  Copyright © 2018年 w.o.c.ward. All rights reserved.
//

#include "Sun.h"

Sun::Sun(float _radius, float _rotationSpeed, GLuint _texid)    :
    radius(_radius), rotationSpeed(_rotationSpeed)
{
    texid = _texid;
    // Check if texture is available
    if (_texid != NULL)
        toTexture = true;
}

void Sun::Display()
{
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    // Sun emits light. Set emission lighting effect
    float mat_emission[] = {1.f, 1.f, 1.f, 1.f};
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mat_emission);
    
    // Adjust the orientation
    glPushMatrix();
        glRotatef(-90.f, 1.f, 0.f, 0.f);
    glPopMatrix();
    
    // Rotation arount y-axis
    glRotatef(rotationAngle, 0.f, 1.f, 0.f);
    
    // Set texture for sphere
    GLUquadricObj* qobj = gluNewQuadric();
    gluQuadricDrawStyle(qobj, GLU_FILL);
    gluQuadricTexture(qobj, GL_TRUE);
    gluQuadricNormals(qobj, GLU_SMOOTH);
    if (toTexture)
    {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texid);
    }
    
    // Draw sphere
    gluSphere(qobj, radius, static_cast<GLint>(30), static_cast<GLint>(30));
    
    if (toTexture)  glDisable(GL_TEXTURE_2D);
    
    glPopAttrib();
    glPopMatrix();
}

void Sun::Update(const double& deltaTime)
{
    float dT = static_cast<float>(deltaTime);
    // Calculate current angle
    rotationAngle += rotationSpeed * dT;
    // Get rotation angle in the range [0, 360)
    if (rotationAngle >= 360.f)
        rotationAngle -= 360.f;
}

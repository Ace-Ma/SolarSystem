//
//  Earth.cpp
//  G53GRA.Framework
//
//  Created by Jingxiao Ma on 2018/4/30.
//  Copyright © 2018年 w.o.c.ward. All rights reserved.
//

#include "Earth.h"

// Constructor for earth
Earth::Earth(float _radius, float _distance, float _rotationSpeed, float _revolutionSpeed, float _moon_radius, float _moon_distance, float _moon_rotationSpeed, float _moon_revolutionSpeed, GLuint _texid)    :
radius(_radius), distanceFromSun(_distance), rotationSpeed(_rotationSpeed), revolutionSpeed(_revolutionSpeed), moonDistance(_moon_distance), moonRadius(_moon_radius), moonRotationSpeed(_moon_rotationSpeed), moonRevolutionAngle(_moon_revolutionSpeed)
{
    texid = _texid;
    // Check if texture is available
    if (_texid != NULL)
        toTexture = true;
}

void Earth::Display()
{
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    float mat_color[] = {0.9f, 0.9f, 0.9f, 1.f};    // Color by diffuse reflection
    float mat_ambient[] = {0.05f, 0.05f, 0.05f, 1.f};     // Color by ambient reflection
    // Set material reflection
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    
    // Set revolution (rotate around orbit) animation
    glRotatef(revolutionAngle, 0.f, 1.f, 0.f);
    
    
    glTranslatef(0, 0, distanceFromSun);
    glRotatef(-70.f, 1.f, 0.f, 0.f);
    glRotatef(rotationAngle, 0.f, 0.f, 1.f);
    
    // Draw moon and animate it
    glPushMatrix();
        glRotatef(70.f, 1.f, 0.f, 0.f);
        glRotatef(moonRevolutionAngle, 0.f, 1.f, 0.f);
        glTranslatef(0.f, 0.f, -moonDistance);
        glRotatef(moonRotationAngle, 0.f, 1.f, 0.f);
        glColor3f(0.95f, 0.95f, 0.95f);
        glutSolidSphere(moonRadius, static_cast<GLint>(30),static_cast<GLint>(30));
    glPopMatrix();
    
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

// Update rotation and revolution angles
void Earth::Update(const double& deltaTime)
{
    float dT = static_cast<float>(deltaTime);
    // Calculate current angle
    rotationAngle += rotationSpeed * dT;
    revolutionAngle += revolutionSpeed * dT;
    if (rotationAngle > 360.f)
        rotationAngle -= 360.f;
    if (revolutionAngle > 360.f)
        revolutionAngle -= 360.f;
  
    moonRotationAngle += moonRotationSpeed * dT;
    moonRevolutionAngle += moonRevolutionSpeed * dT;
    if (moonRotationAngle > 360.f)
        moonRotationAngle -= 360.f;
    if(moonRevolutionAngle > 360.f)
        moonRevolutionAngle -= 360.f;
}



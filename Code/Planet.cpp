//
//  Planet.cpp
//  G53GRA.Framework
//
//  Created by Jingxiao Ma on 2018/4/30.
//  Copyright © 2018年 w.o.c.ward. All rights reserved.
//

#include "Planet.h"

// Constructor for normal planet
Planet::Planet(float _radius, float _distance, float _rotationSpeed, float _revolutionSpeed, GLuint _texid)   :
    radius(_radius), distanceFromSun(_distance), rotationSpeed(_rotationSpeed),
    revolutionSpeed(_revolutionSpeed)
{
    texid = _texid;
    // Check if texture is available
    if (_texid != NULL)
        toTexture = true;
}


void Planet::Display()
{
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    float mat_color[] = {0.9f, 0.9f, 0.9f, 1.f};    // Color by diffuse reflection (light)
    float mat_ambient[] = {0.05f, 0.05f, 0.05f, 1.f};     // Color by ambient reflection (dark)
    // Set material reflection
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    
    // Set revolution (revolve around sun) animation
    glRotatef(revolutionAngle, 0.f, 1.f, 0.f);
    
    glTranslatef(0, 0, distanceFromSun);
    glRotatef(-70.f, 1.f, 0.f, 0.f);    // Ecliptic obliquity
    // Set rotation (rotate itself around center axis) animation
    glRotatef(rotationAngle, 0.f, 0.f, 1.f);
    
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
    
    // If the planet is saturn, draw the cycle
    if (texCycle != NULL)
    {
        glRotatef(90.f, 1.f, 0.f, 0.f);
        glBindTexture(GL_TEXTURE_2D, texCycle);
        glBegin(GL_QUADS);
        glTexCoord2f(0.f, 0.f);
        glVertex3f(-2.5 * radius, 0.f, -2.5 * radius);
        glTexCoord2f(1.f, 0.f);
        glVertex3f(2.5 * radius, 0.f, -2.5 * radius);
        glTexCoord2f(1.f, 1.f);
        glVertex3f(2.5 * radius, 0.f, 2.5 * radius);
        glTexCoord2f(0.f, 1.f);
        glVertex3f(-2.5 * radius, 0.f, 2.5 * radius);
        glEnd();
        
        glBegin(GL_QUADS);
        glTexCoord2f(0.f, 0.f);
        glVertex3f(-2.5 * radius, 0.f, -2.5 * radius);
        glTexCoord2f(1.f, 0.f);
        glVertex3f(-2.5 * radius, 0.f, 2.5 * radius);
        glTexCoord2f(1.f, 1.f);
        glVertex3f(2.5 * radius, 0.f, 2.5 * radius);
        glTexCoord2f(0.f, 1.f);
        glVertex3f(2.5 * radius, 0.f, -2.5 * radius);
        glEnd();
    }
    
    if (toTexture)  glDisable(GL_TEXTURE_2D);
    
    glPopAttrib();
    glPopMatrix();
    
}

// Update angles of rotation and revolution based on current time
void Planet::Update(const double& deltaTime)
{
    float dT = static_cast<float>(deltaTime);
    // Calculate current angle
    rotationAngle += rotationSpeed * dT;
    revolutionAngle += revolutionSpeed * dT;
    if (rotationAngle > 360.f)
        rotationAngle -= 360.f;
    if (revolutionAngle > 360.f)
        revolutionAngle -= 360.f;
}

// Set the ID of texture of Saturn ring
void Planet::setCycleTexture(GLuint _texCycle)
{
    texCycle = _texCycle;
}

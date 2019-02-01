//
//  Satellite.cpp
//  G53GRA.Framework
//
//  Created by Jingxiao Ma on 2018/4/30.
//  Copyright © 2018年 w.o.c.ward. All rights reserved.
//

#include "Satellite.h"

Satellite::Satellite(float _scale, float _x, float _y, float _z, float _animationTime)  :
    scale(_scale), animationTime(_animationTime)
{
    // Locate the world coordinate of object
    new_pos[0] = _x;
    new_pos[1] = _y;
    new_pos[2] = _z;
}

void Satellite::Display()
{
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    // Change position based on input
    glTranslatef(new_pos[0], new_pos[1], new_pos[2]);
    
    // Animation: satellite rotation
    glRotated(satelliteRotation, 0.f, 0.f, 1.f);
    glRotated(satelliteRotation, 1.f, 0.f, 0.f);
    
    // Scale the object
    glScalef(scale, scale, scale);
    // Color: violet
    glColor3f(0.7f, 0.2f, 0.7f);
    // Draw body
    glutSolidCube(1.f);
    
    // Draw left wing
    glPushMatrix();
        glRotated(90.f, 0.f, 0.f, 1.f);
        glRotated(leftWingAngel, 0.f, 1.f, 0.f);
        glTranslatef(0.f, 0.5f, 0.f);
        drawWing();
    glPopMatrix();
    
    // Draw right wing
    glPushMatrix();
        glRotated(-90.f, 0.f, 0.f, 1.f);
        glRotated(rightWingAngel, 0.f, 1.f, 0.f);
        glTranslatef(0.f, 0.5f, 0.f);
        drawWing();
    glPopMatrix();
    
    // Draw head
    glPushMatrix();
        glTranslatef(0.f, 0.5f, 0.f);
        drawHead();
    glPopMatrix();
    
    glPopAttrib();
    glPopMatrix();
}

// Update angles to animate the satellite
void Satellite::Update(const double& deltaTime)
{
    float dT = static_cast<float>(deltaTime);
    leftWingAngel += 40.f * dT;
    rightWingAngel += 40.f * dT;
    satelliteRotation += 20.f * dT;
    if (leftWingAngel >= 360.f)
        leftWingAngel -= 360.f;
    if (rightWingAngel >= 360.f)
        rightWingAngel -= 360.f;
    if (satelliteRotation >= 360.f)
        satelliteRotation -= 360.f;
}

// Draw head, which consists of a gray column and a red sphere
void Satellite::drawHead()
{
    glPushMatrix();
    glColor3f(0.3f, 0.3f, 0.3f);
    drawColumn(0.1f, 0.4f);
    glTranslatef(0.f, 0.6f, 0.f);
    glColor3f(0.8f, 0.3f, 0.3f);
    glutSolidSphere(0.3f, static_cast<GLint>(12), static_cast<GLint>(12));
    glPopMatrix();
}

// Draw wing, which consists of a gray column and a blue board (facet)
void Satellite::drawWing()
{
    glPushMatrix();
    glColor3f(0.3f, 0.3f, 0.3f);
    drawColumn(0.1f, 1.f);
    glColor3f(0.3f, 0.3f, 0.9f);
    glBegin(GL_QUADS);
    glVertex3f(-0.8f, 1.f, 0.f);
    glVertex3f(0.8f, 1.f, 0.f);
    glVertex3f(0.8f, 3.f, 0.f);
    glVertex3f(-0.8f, 3.f, 0.f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(-0.8f, 1.f, 0.f);
    glVertex3f(-0.8f, 3.f, 0.f);
    glVertex3f(0.8f, 3.f, 0.f);
    glVertex3f(0.8f, 1.f, 0.f);
    glEnd();
    glPopMatrix();
}

// Draw a column based on radius and height value
void Satellite::drawColumn(float radius, float height)
{
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    float res = 0.1 * M_PI;     // Resolution
    float x = radius, z = 0.f;
    float t = 0.f;
    
    do{
        glBegin(GL_QUADS);
        glNormal3f(x, 0.f, z);
        glVertex3f(x, 0.f, z);
        glVertex3f(x, height, z);
        
        t += res;
        x = radius * cos(t);
        z = radius * sin(t);
        glNormal3f(x, 0.f, z);
        glVertex3f(x, height, z);
        glVertex3f(x, 0.f, z);
        glEnd();
    } while (t <= 2 * M_PI);
    
    glPopAttrib();
    glPopMatrix();
}

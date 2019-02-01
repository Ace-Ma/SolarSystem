//
//  Astronaut.cpp
//  G53GRA.Framework
//
//  Created by Jingxiao Ma on 2018/4/30.
//  Copyright © 2018年 w.o.c.ward. All rights reserved.
//

#include "Astronaut.h"

Astronaut::Astronaut(float _scale, float _x, float _y, float _z, float _animationTime)  :
    scale(_scale), animationTime(_animationTime)
{
    new_pos[0] = _x;
    new_pos[1] = _y;
    new_pos[2] = _z;
}

void Astronaut::Display()
{
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    float mat_color[] = {0.7f, 0.9f, 0.9f, 1.f};    // Color by diffuse reflection
    float mat_ambient[] = {0.7f, 0.7f, 0.7f, 1.f};     // Color by ambient reflection
    
    // Set material lighting property
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    
    // Change position
    glTranslatef(new_pos[0], new_pos[1], new_pos[2]);
    
    // Scale the object
    glScalef(scale, scale, scale);
    
    // Animation: move around
    glTranslatef(0.f, movement_y, 0.f);
    glColor3f(0.7f, 0.7f, 0.7f);    // Set color to light gray
    
    // Draw body
    glPushMatrix();
        glScalef(1.f, 1.6f, 0.5f);
        glutSolidCube(1.f);
    glPopMatrix();
    
    // Draw head
    glPushMatrix();
        glTranslatef(0.f, 1.2f, 0.f);
        glutSolidSphere(0.5f, static_cast<GLint>(12), static_cast<GLint>(12));
    glPopMatrix();
    
    // Draw left arm
    glPushMatrix();
        glTranslatef(-0.55f, 0.7f, 0.f);
        glutSolidSphere(0.1f, static_cast<GLint>(12), static_cast<GLint>(12));
        drawArm(leftArm1, leftArm2, true);
    glPopMatrix();
    
    // Draw right arm
    glPushMatrix();
        glTranslatef(0.55f, 0.7f, 0.f);
        glutSolidSphere(0.1f, static_cast<GLint>(12), static_cast<GLint>(12));
        drawArm(rightArm1, rightArm2, false);
    glPopMatrix();
    
    // Draw left leg
    glPushMatrix();
        glTranslatef(-0.3f, -0.77f, 0.f);
        glutSolidSphere(0.1f, static_cast<GLint>(12), static_cast<GLint>(12));
        drawLeg(leftLeg);
    glPopMatrix();
    
    // Draw right leg
    glPushMatrix();
        glTranslatef(0.3f, -0.77f, 0.f);
        glutSolidSphere(0.1f, static_cast<GLint>(12), static_cast<GLint>(12));
        drawLeg(rightLeg);
    glPopMatrix();
    
    glPopAttrib();
    glPopMatrix();
}

// Update gesture of astronaut
void Astronaut::Update(const double &deltaTime)
{
    float dT = static_cast<float>(deltaTime);
    aT = fmod(aT + dT, animationTime);
    float aS = 18.f * aT / animationTime;
    if (aS < 1.f || aS > 17.f){
        movement_y = 0.1f;
        leftArm1 = -30.f;
        leftArm2 = 80.f;
        rightArm1 = 30.f;
        rightArm2 = 10.f;
        leftLeg = 20.f;
        rightLeg = -20.f;
    }
    else if(aS < 2.f || aS > 16.f){
        movement_y = 0.1f;
        leftArm1 = -22.5f;
        leftArm2 = 71.25f;
        rightArm1 = 22.5f;
        rightArm2 = 18.75f;
        leftLeg = 15.f;
        rightLeg = -15.f;
    }
    else if(aS < 3.f || aS > 15.f){
        movement_y = 0.1f;
        leftArm1 = -15.f;
        leftArm2 = 62.5f;
        rightArm1 = 15.f;
        rightArm2 = 27.5f;
        leftLeg = 10.f;
        rightLeg = -10.f;
    }
    else if(aS < 4.f || aS > 14.f){
        movement_y = 0.1f;
        leftArm1 = -7.5f;
        leftArm2 = 53.75f;
        rightArm1 = 7.5f;
        rightArm2 = 36.25f;
        leftLeg = 5.f;
        rightLeg = -5.f;
    }
    else if(aS < 5.f || aS > 13.f){
        movement_y = 0.f;
        leftArm1 = -0.f;
        leftArm2 = 45.f;
        rightArm1 = 0.f;
        rightArm2 = 45.f;
        leftLeg = 0.f;
        rightLeg = 0.f;
    }
    else if(aS < 6.f || aS > 12.f){
        movement_y = -0.1f;
        leftArm1 = 7.5f;
        leftArm2 = 36.25f;
        rightArm1 = -7.5f;
        rightArm2 = 53.75f;
        leftLeg = -5.f;
        rightLeg = 5.f;
    }
    else if(aS < 7.f || aS > 11.f){
        movement_y = -0.1f;
        leftArm1 = 15.f;
        leftArm2 = 27.5f;
        rightArm1 = -15.f;
        rightArm2 = 62.5f;
        leftLeg = -10.f;
        rightLeg = 10.f;
    }
    else if(aS < 8.f || aS > 10.f){
        movement_y = -0.1f;
        leftArm1 = 22.5f;
        leftArm2 = 18.75f;
        rightArm1 = -22.5f;
        rightArm2 = 71.25f;
        leftLeg = -15.f;
        rightLeg = 15.f;
    }
    else{
        movement_y = -0.1f;
        leftArm1 = 30.f;
        leftArm2 = 10.f;
        rightArm1 = -30.f;
        rightArm2 = 80.f;
        leftLeg = -20.f;
        rightLeg = 20.f;
    }
    
    
}

void Astronaut::drawArm(float r1, float r2, bool isLeft)
{
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
        // Rotate based on left or right
        if (isLeft)
            glRotatef(160.f, 0.f, 0.f, 1.f);
        else
            glRotatef(-160.f, 0.f, 0.f, 1.f);
    
        glRotatef(r1, 1.f, 0.f, 0.f);
        // Draw first part of arm
        drawColumn(0.1f, 0.7f);
        glTranslatef(0.f, 0.7f, 0.f);
        // Draw joint
        glutSolidSphere(0.1f, static_cast<GLint>(12), static_cast<GLint>(12));
        glRotatef(-r2, 1.f, 0.f, 0.f);
        // Draw second part of arm
        drawColumn(0.1f, 0.6f);
        glTranslatef(0.f, 0.65f, 0.f);
        glutSolidSphere(0.2f, static_cast<GLint>(12), static_cast<GLint>(12));
    
    glPopAttrib();
    glPopMatrix();
}

void Astronaut::drawLeg(float r)
{
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
        glRotatef(180.f, 0.f, 0.f, 1.f);
        glRotatef(r, 1.f, 0.f, 0.f);
        // Draw first part of leg
        drawColumn(0.1f, 0.8f);
        glTranslatef(0.f, 0.8f, 0.f);
    
        glRotatef(25.f, 1.f, 0.f, 0.f);
        // Draw the joint
        glutSolidSphere(0.1f, static_cast<GLint>(12), static_cast<GLint>(12));
        // Draw second part of leg
        drawColumn(0.1f, 0.6f);
        glTranslatef(0.f, 0.6f, -0.1f);
        // Draw feet
        glScalef(0.2f, 0.05f, 0.4f);
        glutSolidCube(1.f);
    
    glPopAttrib();
    glPopMatrix();
}

// Draw a column based on radius and height value
void Astronaut::drawColumn(float radius, float height)
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

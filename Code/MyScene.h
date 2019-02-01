#pragma once

#include "../Framework/Engine/Scene.h"
#include "Stage.h"
#include "Astronaut.h"
#include "Sun.h"
#include "Earth.h"
#include "Planet.h"
#include "Satellite.h"

class MyScene :
	public Scene
{
public:
	MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight);
	~MyScene() {};
    
    void setGlobalLight();

private:
	void Initialise();
	void Projection();

};

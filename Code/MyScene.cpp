#include "MyScene.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    
    // Get eye position for further calculation
    float eye[3];
    GetCamera()->GetEyePosition(eye[0], eye[1], eye[2]);
    
    // Load texture of skybox
    GLuint* skybox = new GLuint[6];
    skybox[0] = GetTexture("./left.bmp");
    skybox[1] = GetTexture("./right.bmp");
    skybox[2] = GetTexture("./front.bmp");
    skybox[3] = GetTexture("./back.bmp");
    skybox[4] = GetTexture("./down.bmp");
    skybox[5] = GetTexture("./up.bmp");
    // Initialize galaxy skybox
    Stage* stage = new Stage(1500.f, skybox);
    
    // Create sun
    GLuint texSun = GetTexture("./Sun.bmp");
    Sun* sun = new Sun(30.f, 150.f, texSun);
    
    // Create Mercury
    GLuint texMercury = GetTexture("./Mercury.bmp");
    Planet* mercury = new Planet(3.f, 60.f, 180.f, 45.f, texMercury);
    
    // Create Venus
    GLuint texVenus = GetTexture("./Venus.bmp");
    Planet* venus = new Planet(3.f, 95.f, 160.f, 30.f, texVenus);
    
    // Create Earth
    GLuint texEarth = GetTexture("./Earth.bmp");
    Earth* earth = new Earth(5.f, 140.f, 130.f, 20.f, 2.f, 10.f, 130.f, 40.f, texEarth);
    
    // Create Mars
    GLuint texMars = GetTexture("./Mars.bmp");
    Planet* mars = new Planet(7.f, 180.f, 100.f, 16.f, texMars);
    
    // Create Jupiter
    GLuint texJupiter = GetTexture("./Jupiter.bmp");
    Planet* jupiter = new Planet(32.f, 280.f, 80.f, 15.f, texJupiter);
    
    // Create Saturn
    GLuint texSaturn = GetTexture("./Saturn.bmp");
    Planet* saturn = new Planet(22.f, 400.f, 70.f, 12.f, texSaturn);
    GLuint texSaturnCycle = GetTexture("./Saturn_cycle.bmp");
    saturn->setCycleTexture(texSaturnCycle);
    
    // Create uranus
    GLuint texUranus = GetTexture("./Uranus.bmp");
    Planet* uranus = new Planet(12.f, 480.f, 55.f, 10.f, texUranus);
    
    // Create Neptune
    GLuint texNeptune = GetTexture("./Neptune.bmp");
    Planet* neptune = new Planet(12.f, 550.f, 40.f, 10.f, texNeptune);
    
    // Create Pluto
    GLuint texPluto = GetTexture("./Pluto.bmp");
    Planet* pluto = new Planet(2.f, 630.f, 20.f, 10.f, texPluto);
    
    // Create astronaut object
    Astronaut* astronaut = new Astronaut(.5f, eye[0]+3.f, eye[1]+3.f, eye[2]-9.f, 3.f);
    
    // Create satellite object
    Satellite* satellite = new Satellite(2.f, eye[0]-10.f, eye[1]-10.f, eye[2]-25.f, 3.f);
    
    
    AddObjectToScene(stage);
    AddObjectToScene(astronaut);
    AddObjectToScene(sun);
    AddObjectToScene(mercury);
    AddObjectToScene(venus);
    AddObjectToScene(earth);
    AddObjectToScene(mars);
    AddObjectToScene(jupiter);
    AddObjectToScene(saturn);
    AddObjectToScene(uranus);
    AddObjectToScene(neptune);
    AddObjectToScene(pluto);
    AddObjectToScene(satellite);
}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 5200.0);
}

// Set global light information
void MyScene::setGlobalLight()
{
    float ambient[4] = {.1f, .1f, .1f, 1.f};
    float diffuse[4] = {.8f, .8f, .8f, 1.f};
    float specular[4] = {.8f, .8f, .8f, 1.f};
    float position[4] = {0.f, 0.f, 0.f, 1.f};
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

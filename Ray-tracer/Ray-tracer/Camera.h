#pragma once

#include <iostream>
#include <fstream>
#include <vector>

#include "glm/glm.hpp"
#include "Pixel.h"
#include "Scene.h"

const int SIZE = 20;

class Camera
{
public:
	Camera();
	~Camera();

	void render(Scene scene);

	void createImage();

	void setEye(int _eye);

private:
	glm::vec4 eye00 = glm::vec4(-2,0,0,1);
	glm::vec4 eye01 = glm::vec4(-1,0,0,1);
	int eyeSwitch;

	Pixel image[SIZE][SIZE];
};


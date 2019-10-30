#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <omp.h>

#include "glm/glm.hpp"
#include "Pixel.h"
#include "Scene.h"

//SHOULD BE 800
const int SIZE = 800;
const int SUB_SIZE = 2;
const bool AA = true;

class Camera
{
public:
	Camera() : image(SIZE, std::vector<Pixel>(SIZE)) {};
	~Camera();

	void render(Scene scene);
	void createImage();
	void setEye(int _eye);

private:
	glm::vec3 eye00 = glm::vec3(-2,0,0);
	glm::vec3 eye01 = glm::vec3( -1,0,0);
	int eyeSwitch = 1;
	std::vector<std::vector<Pixel>> image;
};


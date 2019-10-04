#pragma once

#include <iostream>
#include <fstream>
#include <vector>

#include "glm/glm.hpp"
#include "Pixel.h"
#include "Scene.h"

//SHOULD BE 800
const int SIZE = 800;

class Camera
{
public:
	Camera() : image(SIZE, std::vector<Pixel>(SIZE)) {};
	~Camera();

	void render(Scene scene);

	void createImage();

	void setEye(int _eye);

private:
	glm::vec4 eye00 = glm::vec4(-2,0,0,1);
	glm::vec4 eye01 = glm::vec4( -1,0,0,1);
	int eyeSwitch;
	std::vector<std::vector<Pixel>> image;
};


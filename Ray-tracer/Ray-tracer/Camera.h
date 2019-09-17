#pragma once

#include <iostream>
#include <fstream>

#include "glm/glm.hpp"
#include "Vertex.h"
#include "Pixel.h"

const int SIZE = 800;

class Camera
{
public:
	Camera();
	~Camera();

	void render() {
		//Launch ray... each pixel
	}

	void createImage();

private:
	Vertex eye00;
	Vertex eye01;
	int eyeSwitch;

	Pixel image[SIZE][SIZE];
};


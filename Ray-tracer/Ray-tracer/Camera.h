#pragma once

#include <iostream>
#include <fstream>
#include <vector>

#include "Vertex.h"
#include "Pixel.h"

const int SIZE = 800;

class Camera
{
public:
	Camera();
	~Camera();

	void render();

	void createImage();

	void setEye(int _eye);

private:
	Vertex eye00 = Vertex(-2,0,0,1);
	Vertex eye01 = Vertex(-1,0,0,1);
	int eyeSwitch;

	Pixel image[SIZE][SIZE];
	//std::array<std::array<Pixel, SIZE>, SIZE> image;
	//std::vector<std::vector<Pixel>> x(std::vector<int>(500)), 5000);
};


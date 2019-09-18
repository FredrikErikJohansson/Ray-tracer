#include "Camera.h"
#include "glm/glm.hpp"

#include <stdlib.h>
#include <stdio.h>

Camera::Camera()
{
}

Camera::~Camera()
{
}

/*
void Camera::createImage() {

	std::ofstream myfile;
	myfile.open("example.txt");

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			myfile << image[i][j].getColor().getRed() << std::endl;
		}
	}
	myfile.close();
}*/

void Camera::createImage() {

	FILE *fp = fopen("rendering.ppm", "wb"); /* b - binary mode */
	fprintf(fp, "P6\n%d %d\n255\n", SIZE, SIZE);
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			static unsigned char color[3];
			color[0] = image[i][j].getColor().getRed();  /* red */
			color[1] = image[i][j].getColor().getGreen();  /* green */
			color[2] = image[i][j].getColor().getBlue();  /* blue */
			fwrite(color, 1, 3, fp);
		}
	}
	fclose(fp);
}

void Camera::render() {
	double currentPixelZ = 0.99875;
	double currentPixelY = -0.99875;

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {

			if(eyeSwitch == 0)
				Ray ray = Ray(eye00, Vertex(0,currentPixelY,currentPixelZ,1));
			else Ray ray = Ray(eye01, Vertex(0,currentPixelY,currentPixelZ,1));

			//Follow the ray
			//and then give image some values
			image[i][j].setColor(255, 0, 0); //This is for test

			currentPixelY += currentPixelY + 0.0025;
		}
		currentPixelY = -0.99875;
		currentPixelZ -= currentPixelZ - 0.0025;
	}
}

void Camera::setEye(int _eye) {
	if (_eye == 0 || _eye == 1)
		eyeSwitch = _eye;
	else eyeSwitch = 0;
}

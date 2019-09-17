#include "pch.h"
#include "Camera.h"


Camera::Camera()
{
}

Camera::~Camera()
{
}

void Camera::createImage() {
	std::ofstream myfile;
	myfile.open("example.txt");

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			myfile << image[i][j].getColor().getRed() <<
				" : " << image[i][j].getColor().getGreen() <<
				" : " << image[i][j].getColor().getBlue() <<
				std::endl;
		}
	}
	myfile.close();
}

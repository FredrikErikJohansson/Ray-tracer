#include "Camera.h"

#include <stdlib.h>
#include <stdio.h>

Camera::Camera()
{
}

Camera::~Camera()
{
}


void Camera::createImage() {

	FILE *fp = fopen("rendering.ppm", "wb"); /* b - binary mode */
	fprintf(fp, "P6\n%d %d\n255\n", SIZE, SIZE);
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			static unsigned char color[3];
			color[0] = image[i][j].getColor().x;  /* red */
			color[1] = image[i][j].getColor().y;  /* green */
			color[2] = image[i][j].getColor().z;  /* blue */
			fwrite(color, 1, 3, fp);
		}
	}
	fclose(fp);
}

void Camera::render(Scene scene) {
	double currentPixelZ = 0.99875;
	double currentPixelY = -0.99875;

	for (int i = 0; i < SIZE; i++) {
		//std::cout << i << std::endl;
		for (int j = 0; j < SIZE; j++) {

			Ray ray;

			if(eyeSwitch == 0)
				ray = Ray(eye00, glm::vec4(0,currentPixelY,currentPixelZ,1));
			else ray = Ray(eye01, glm::vec4(0,currentPixelY,currentPixelZ,1));

			//Follow the ray
			//and then give image some values
			glm::vec3 pixelColor = scene.getIntersectedTriangle(ray).getColor();

			image[i][j].setColor(pixelColor.x * 256, pixelColor.y * 256, pixelColor.z * 256);
			std::cout << "Red: " << image[i][j].getColor().x << " Green: " << image[i][j].getColor().y << " Blue: " << image[i][j].getColor().z << std::endl;

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

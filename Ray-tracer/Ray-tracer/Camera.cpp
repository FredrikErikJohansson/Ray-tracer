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
	for (int j = SIZE-1; j > -1; --j)
	{
		for (int i = SIZE-1; i > -1; --i)
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
	for (int i = 0; i < SIZE; i++) {
		std::cout << i << "/" << SIZE << std::endl;
		for (int j = 0; j < SIZE; j++) {

			Ray ray;
			glm::vec3 currentPixel = (glm::vec3(eye01) + glm::vec3(0, i*0.0025 - 0.99875, j*0.0025 - 0.99875) - glm::vec3(eye01));
			ray = Ray(eye01, glm::vec4(currentPixel, 1));

			//if(eyeSwitch == 0)
				//ray = Ray(eye00, glm::vec4(0,currentPixelY,currentPixelZ,1));
			//else ray = Ray(eye01, glm::vec4(0,currentPixelY,currentPixelZ,1));

			//Follow the ray
			//and then give image some values
			float pixelBrightness = scene.getIntersectedTriangle(ray).getBrightness();
			glm::vec3 pixelColor = scene.getIntersectedTriangle(ray).getColor()*pixelBrightness;

			
			//std::cout << "Red: " << scene.getIntersectedTriangle(ray).getColor().x << std::endl;

			image[i][j].setColor(pixelColor.x*pixelBrightness*25, pixelColor.y*pixelBrightness*25, pixelColor.z*pixelBrightness*25);
			//std::cout << "Red: " << image[i][j].getColor().x << std::endl;
		}
	}
}

void Camera::setEye(int _eye) {
	if (_eye == 0 || _eye == 1)
		eyeSwitch = _eye;
	else eyeSwitch = 0;
}

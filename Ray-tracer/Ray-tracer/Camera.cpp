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
	float maxVal = 0;

	for (int i = 0; i < SIZE; i++) {
		if ( i % 79 == 0 ) std::cout << i + 1 << "/" << SIZE << std::endl;
		for (int j = 0; j < SIZE; j++) {
			Ray ray;
			glm::vec3 currentPixel = (glm::vec3(eye01) + glm::vec3(0, i*0.0025f - 0.99875f, j*0.0025f - 0.99875f) - glm::vec3(eye01));
			ray = Ray(eye01, glm::vec4(currentPixel, 1));

			//Follow the ray and then give image some values
			Triangle currentTriangle = scene.getIntersectedTriangle(ray);
			float pixelBrightness = currentTriangle.getBrightness();
			glm::vec3 pixelColor = currentTriangle.getColor()*pixelBrightness;

			if (glm::max(glm::max(pixelColor.x, pixelColor.y), pixelColor.z) > maxVal)
				maxVal = glm::max(glm::max(pixelColor.x, pixelColor.y), pixelColor.z);

			image[i][j].setColor(pixelColor.x, pixelColor.y, pixelColor.z);
		}
	}
	
	glm::vec3 currentColor;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			currentColor = image[i][j].getColor();
			image[i][j].setColor(currentColor*(255.99f / maxVal));
		}
	}
}

void Camera::setEye(int _eye) {
	if (_eye == 0 || _eye == 1)
		eyeSwitch = _eye;
	else eyeSwitch = 0;
}

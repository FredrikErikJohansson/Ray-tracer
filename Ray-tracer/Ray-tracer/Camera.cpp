#include "Camera.h"

#include <stdlib.h>
#include <stdio.h>

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
			color[0] = (unsigned char)image[i][j].getColor().x;  /* red */
			color[1] = (unsigned char)image[i][j].getColor().y;  /* green */
			color[2] = (unsigned char)image[i][j].getColor().z;  /* blue */
			fwrite(color, 1, 3, fp);
		}
	}
	fclose(fp);
}

void Camera::render(Scene scene) {
	float maxVal = 0;
	Ray ray;
	glm::vec3 currentPixel;
	glm::vec3 eye;

	if (eyeSwitch) eye = eye01;
	else eye = eye00;

	Intersection isec;
	float pixelBrightness;
	glm::vec3 pixelColor;
	Ray shadowRay;

	for (register size_t i = 0; i < SIZE; i++) {
		if ( i % 10 == 0 ) std::cout << i + 1 << "/" << SIZE << std::endl;
		for (register size_t j = 0; j < SIZE; j++) {

			//Camera position
			currentPixel = eye + glm::vec3(0, i*(2.0f/SIZE) - (1-(1/SIZE)), j*(2.0f / SIZE) - (1 - (1 / SIZE))) - glm::vec3(eye01);
			ray = Ray(eye01, glm::vec4(currentPixel, 1));

			//Follow the ray and store the first intersection
			isec = scene.getIntersection(ray);

			//Check if we have atleast one intersection
			if (isec.getTriHits() == 0 && isec.getSphHits() == 0) {
				std::cout << "Err: No point hit" << std::endl;
				pixelColor = glm::vec3(0, 1, 0);
				continue;
			}

			if (isec.getClosest() == "SPHERE") {
				pixelBrightness = isec.getSphere().getBrightness();
				pixelColor = isec.getSphere().getColor()*pixelBrightness;
			}
			else {
				pixelBrightness = isec.getTriangle().getBrightness();
				pixelColor = isec.getTriangle().getColor()*pixelBrightness;
			}

			//Check if the intersection is visible
			shadowRay = Ray(isec.getPoint(), glm::vec3(5, 0, 4));
			if (isec.getPoint().z < 4.0f && !scene.isVisible(shadowRay)) pixelColor *= 0.0f;

			//Store the highest color value
			if (glm::max(glm::max(pixelColor.x, pixelColor.y), pixelColor.z) > maxVal)
				maxVal = glm::max(glm::max(pixelColor.x, pixelColor.y), pixelColor.z);

			image[i][j].setColor(pixelColor.x, pixelColor.y, pixelColor.z);
		}
	}
	
	//Map the color values from the max values
	glm::vec3 currentColor;
	for (register size_t i = 0; i < SIZE; i++) {
		for (register size_t j = 0; j < SIZE; j++) {
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

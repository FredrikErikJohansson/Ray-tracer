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

	for (register size_t i = 0; i < SIZE; i++) {
		if ( i % 79 == 0 ) std::cout << i + 1 << "/" << SIZE << std::endl;
		for (register size_t j = 0; j < SIZE; j++) {

			//Camera position for 800x800
			if(eyeSwitch){
				currentPixel = glm::vec3(eye01) + glm::vec3(0, i*0.0025f - 0.99875f, j*0.0025f - 0.99875f) - glm::vec3(eye01);
				ray = Ray(eye01, glm::vec4(currentPixel, 1));
			}
			else {
				currentPixel = glm::vec3(eye00) + glm::vec3(0, i*0.0025f - 0.99875f, j*0.0025f - 0.99875f) - glm::vec3(eye00);
				ray = Ray(eye00, glm::vec4(currentPixel, 1));
			}

			//Follow the ray and store the first intersection
			TriangleIntersection triangleIntersection = scene.triangleIntersections(ray);
			SphereIntersection sphereIntersection = scene.sphereIntersections(ray);

			float distanceToTriangle = 1000.0f;
			float distanceToSphere = 1000.0f;

			float pixelBrightness;
			glm::vec3 pixelColor;
			Ray shadowRay;

			//Check if we have atleast one intersection
			if (triangleIntersection.point.x > 999.0f && sphereIntersection.point.x > 999.0f) {
				std::cout << "Err: No point hit" << std::endl;
				pixelColor = glm::vec3(1, 0, 0);
				continue;
			}

			//Check if we have triangle intersection(s)
			if (triangleIntersection.point.x < 999.0f) {
				distanceToTriangle = glm::length(glm::vec3(ray.getStartPoint()) - triangleIntersection.point);
			}

			//Check if we have sphere intersection(s)
			if (sphereIntersection.point.x < 999.0f) {
				distanceToSphere = glm::length(glm::vec3(ray.getStartPoint()) - sphereIntersection.point);
			}
	
			//Check for first intersection and set the correct pixel value
			if (distanceToSphere < distanceToTriangle) {

				pixelBrightness = sphereIntersection.sphere.getBrightness();
				pixelColor = sphereIntersection.sphere.getColor()*pixelBrightness;

				//Check if sphere is visible
				shadowRay = Ray(sphereIntersection.point, glm::vec3(5, 0, 4));
				if (!scene.isVisible(shadowRay)) pixelColor *= 0.0f;

			}	
			else if (distanceToSphere > distanceToTriangle) {
				pixelBrightness = triangleIntersection.triangle.getBrightness();
				pixelColor = triangleIntersection.triangle.getColor()*pixelBrightness;

				//Check if triangle is visible
				shadowRay = Ray(triangleIntersection.point, glm::vec3(5, 0, 4));
				//If triangle is above lightsource !skip
				if (triangleIntersection.point.z < 4.0f && !scene.isVisible(shadowRay)) pixelColor *= 0.0f;
			}

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

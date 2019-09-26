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
	Ray ray;
	glm::vec3 currentPixel;

	for (int i = 0; i < SIZE; i++) {
		if ( i % 79 == 0 ) std::cout << i + 1 << "/" << SIZE << std::endl;
		for (int j = 0; j < SIZE; j++) {

			//Camera position
			if(eyeSwitch){
				currentPixel = glm::vec3(eye01) + glm::vec3(0, i*0.0025f - 0.99875f, j*0.0025f - 0.99875f) - glm::vec3(eye01);
				ray = Ray(eye01, glm::vec4(currentPixel, 1));
			}
			else {
				currentPixel = glm::vec3(eye00) + glm::vec3(0, i*0.0025f - 0.99875f, j*0.0025f - 0.99875f) - glm::vec3(eye00);
				ray = Ray(eye00, glm::vec4(currentPixel, 1));
			}

			//Follow the ray and store intersections
			std::list<TriangleIntersection> triangleIntersections = scene.triangleIntersections(ray);
			std::list<SphereIntersection> sphereIntersections = scene.sphereIntersections(ray);

			Triangle currentTriangle;
			glm::vec3 currentTrianglePoint;

			Sphere currentSphere;
			glm::vec3 currentSpherePoint;

			float distanceToTriangle = 1000.0f;
			float distanceToSphere = 1000.0f;

			float pixelBrightness;
			glm::vec3 pixelColor;

			//Check if we have triangle intersection(s)
			if (!triangleIntersections.empty()) {
				currentTriangle = triangleIntersections.front().triangle;
				currentTrianglePoint = triangleIntersections.front().point;
				distanceToTriangle = glm::length(glm::vec3(ray.getStartPoint()) - currentTrianglePoint);
			}

			//Check if we have sphere intersection(s)
			if (!sphereIntersections.empty()) {
				currentSphere = sphereIntersections.front().sphere;
				currentSpherePoint = sphereIntersections.front().point;
				distanceToSphere = glm::length(glm::vec3(ray.getStartPoint()) - currentSpherePoint);
			}

			//Check which intersection is closest to camera
			if (distanceToTriangle > distanceToSphere) {

				//Visibility test for sphere
				Ray shadowRay = Ray(currentTrianglePoint, glm::vec3(5, 0, 4));
				if(scene.visibilityTest(shadowRay,"sphere")) pixelBrightness = currentSphere.getBrightness();
				else pixelBrightness = 0;

				pixelColor = currentSphere.getColor()*pixelBrightness;
			}
			else if(distanceToTriangle < distanceToSphere) {

				//Visibility test for triangle
				Ray shadowRay = Ray(currentTrianglePoint, glm::vec3(5, 0, 4));
				if (currentTrianglePoint.z >= 4) pixelBrightness = currentTriangle.getBrightness();
				else {
					if (scene.visibilityTest(shadowRay, "triangle")) pixelBrightness = currentTriangle.getBrightness();
					else pixelBrightness = 0;
				}

				pixelColor = currentTriangle.getColor()*pixelBrightness;
			}
			else {
				std::cout << "Err: pixel (" << i << ", " << j << ")" << " has no hit." << std::endl;
				pixelColor = glm::vec3(0, 1, 0);
			}

			//Store the highest color value
			if (glm::max(glm::max(pixelColor.x, pixelColor.y), pixelColor.z) > maxVal)
				maxVal = glm::max(glm::max(pixelColor.x, pixelColor.y), pixelColor.z);

			image[i][j].setColor(pixelColor.x, pixelColor.y, pixelColor.z);
		}
	}
	
	//Map the color values from the max values
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

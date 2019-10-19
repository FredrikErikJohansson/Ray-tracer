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
	float step = (1.0f / 3.0f*SIZE);
	Ray ray;
	glm::vec3 currentPixel;
	glm::vec3 currentSubPixel;
	glm::vec3 eye;

	if (eyeSwitch) eye = eye01;
	else eye = eye00;

	double start, end, runTime;
	start = omp_get_wtime();

	//Intersection isec;
	float pixelBrightness;
	glm::vec3 pixelColor = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 subPixelColor = glm::vec3(0.0f, 0.0f, 0.0f);
	Ray shadowRay;

	IntersectionTree * iTree = new IntersectionTree();

	for (register size_t i = 0; i < SIZE; i++) {
		if ( i % 10 == 0 ) std::cout << i + 1 << "/" << SIZE << std::endl;
		#pragma omp parallel for
		for (register size_t j = 0; j < SIZE; j++) {

			//Camera position
			currentPixel = eye + glm::vec3(0, i*(2.0f / SIZE) - (1 - (1 / SIZE)), j*(2.0f / SIZE) - (1 - (1 / SIZE))) - glm::vec3(eye);
			currentSubPixel = currentPixel;
			//current steglängd for 800x800 = 0.00125 (1/SIZE)
			//we want to split that into 1/4 => 1/(4*SIZE)
			//Then add that into x and y
			//currentPixel = glm::vec3(eye00) + glm::vec3(0, i*0.0025f - 0.99875f, j*0.0025f - 0.99875f) - glm::vec3(eye00);
			//currentPixel = eye + glm::vec3(0, i*(2.0f / 3.0f*SIZE) - (1 - (1 / 3.0f*SIZE)), j*(2.0f / 3.0f*SIZE) - (1 - (1 / 3.0f*SIZE))) - glm::vec3(eye);

			//ray = Ray(eye, glm::vec4(currentPixel, 1));

			//Follow the ray and store the first intersection
			Intersection* root = new Intersection;
			root->R = nullptr;
			root->T = nullptr;
			glm::vec3 pixelColor = glm::vec3(0.0f,0.0f,0.0f);

			//Subrays
			currentSubPixel.y -= (2.0f / 4.0f*SIZE) - (1 - (1 / 4.0f*SIZE));
			currentSubPixel.z -= (2.0f / 4.0f*SIZE) - (1 - (1 / 4.0f*SIZE));
			ray = Ray(eye, glm::vec4(currentPixel, 1));
			subPixelColor += scene.getIntersection(ray, root);
			subPixelColor *= root->radiance;
			pixelColor += subPixelColor;
			currentSubPixel = currentPixel;

			currentSubPixel.y -= (2.0f / 4.0f*SIZE) - (1 - (1 / 4.0f*SIZE));
			currentSubPixel.z += (2.0f / 4.0f*SIZE) - (1 - (1 / 4.0f*SIZE));
			ray = Ray(eye, glm::vec4(currentPixel, 1));
			subPixelColor += scene.getIntersection(ray, root);
			subPixelColor *= root->radiance;
			pixelColor += subPixelColor;
			currentSubPixel = currentPixel;

			currentSubPixel.y += (2.0f / 4.0f*SIZE) - (1 - (1 / 4.0f*SIZE));
			currentSubPixel.z -= (2.0f / 4.0f*SIZE) - (1 - (1 / 4.0f*SIZE));
			ray = Ray(eye, glm::vec4(currentPixel, 1));
			subPixelColor += scene.getIntersection(ray, root);
			subPixelColor *= root->radiance;
			pixelColor += subPixelColor;
			currentSubPixel = currentPixel;

			currentSubPixel.y += (2.0f / SIZE) - (1 - (1 / SIZE));
			currentSubPixel.z += (2.0f / SIZE) - (1 - (1 / SIZE));
			subPixelColor += scene.getIntersection(ray, root);
			subPixelColor *= root->radiance;
			pixelColor += subPixelColor;
			currentSubPixel = currentPixel;

			pixelColor = pixelColor / 4.0f;

			//currentPixel = eye + glm::vec3(0, a*(2.0f / 3.0f*SIZE) - (1 - (1 / 3.0f*SIZE)), b*(2.0f / 3.0f*SIZE) - (1 - (1 / 3.0f*SIZE))) - glm::vec3(eye);

			/*for (int a = -1; a < 2; a++) {
				for (int b = -1; b < 2; b++) {
					currentPixel.y += a * (2.0f / 4.0f*SIZE) - (1 - (1 / 4.0f*SIZE));
					currentPixel.z += b * (2.0f / 4.0f*SIZE) - (1 - (1 / 4.0f*SIZE));
					
				}
			}*/
			

			//Store the highest color value
			if (glm::max(glm::max(pixelColor.x, pixelColor.y), pixelColor.z) > maxVal)
				maxVal = glm::max(glm::max(pixelColor.x, pixelColor.y), pixelColor.z);

			image[i][j].setColor(pixelColor.x, pixelColor.y, pixelColor.z);
		}
	}

	delete iTree;
	end = omp_get_wtime();
	runTime = end - start;
	std::cout << "Elapsed time: " << runTime << " seconds." << std::endl;
	
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

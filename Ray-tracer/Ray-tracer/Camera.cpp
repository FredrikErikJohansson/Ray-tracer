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
	glm::vec3 eye;
	if (eyeSwitch) eye = eye01;
	else eye = eye00;

	double start, end, runTime;
	start = omp_get_wtime();
	for (int i = 0; i < SIZE; i++) {
		if (i % 10 == 0) std::cout << "\r" << (i*100)/SIZE << "%";
		#pragma omp parallel for
		for (int j = 0; j < SIZE; j++) {

			Ray ray;
			glm::vec3 pixelColor = glm::vec3(0.0f);
			glm::vec3 currentPixel = glm::vec3(0.0f);
			
			//Camera position
			currentPixel = eye + glm::vec3(0, i*(2.0f / SIZE) - (1 - (1 / SIZE)), j*(2.0f / SIZE) - (1 - (1 / SIZE))) - glm::vec3(eye);

			//Single ray
			//Intersection* root = new Intersection(nullptr);
			//ray = Ray(eye, glm::vec4(currentPixel, 1));
			//pixelColor += scene.getIntersection(ray, root);
			//root->destroy();


			//Supersampling
			float A, B = 1.0f;
			bool inside = false;
			currentPixel.y -= (SIZE - 1) / (2 * SIZE * SIZE);
			currentPixel.z -= (SIZE - 1) / (2 * SIZE * SIZE);
			for (int a = 0; a < SUB_SIZE; a++) {
				for (int b = 0; b < SUB_SIZE; b++) {
					Intersection* root = new Intersection();
					if (AA) {
						A = scene.uniformRand();
						B = scene.uniformRand();
						currentPixel.y += (1 / (SIZE * SIZE) * a) * A;
						currentPixel.z += (1 / (SIZE * SIZE) * b) * B;
					}
					else {
						currentPixel.y += 1 / (2 * SIZE * SIZE) * a;
						currentPixel.z += 1 / (2 * SIZE * SIZE) * b;
					}
					
					ray = Ray(eye, glm::vec4(currentPixel, 1));
					pixelColor += scene.getIntersection(ray, root, inside);
					root->destroy();
				}
			}
			pixelColor /= SUB_SIZE * SUB_SIZE;

			//Store the highest color value
			if (glm::max(glm::max(pixelColor.x, pixelColor.y), pixelColor.z) > maxVal)
				maxVal = glm::max(glm::max(pixelColor.x, pixelColor.y), pixelColor.z);

			image[i][j].setColor(pixelColor.x, pixelColor.y, pixelColor.z);

		}	
	}
	end = omp_get_wtime();
	runTime = end - start;
	std::cout << std::endl;
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

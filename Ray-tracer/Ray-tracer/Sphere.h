#pragma once

#include <math.h>

#include "glm/glm.hpp"
#include "Ray.h"

class Sphere
{
public:
	Sphere();
	~Sphere();

	bool rayIntersection(Ray ray, glm::vec3&);

	float getBrightness() {
		return brightness;
	}

	glm::vec3 getColor() {
		return color;
	}

	void setColor(glm::vec3 _color) {
		color = _color;
	}

	void setCenter(glm::vec3 _center) {
		center = _center;
	}

	void setRadius(float _radius) {
		radius = _radius;
	}

private:
	glm::vec3 center;
	glm::vec3 color;
	float radius;
	float brightness;
};


#pragma once

#include <iostream>
#include <math.h>

#include "glm/glm.hpp"
#include "Ray.h"

class Triangle
{
public:
	Triangle();
	~Triangle();

	bool rayIntersection(Ray arg, glm::vec3&);

	glm::vec3 getColor() {
		return color;
	}

	glm::vec3 getNormal() {
		return glm::normalize(normal);
	}

	float getBrightness() {
		return brightness;
	}

	void setVertices(glm::vec4 _v0, glm::vec4 _v1, glm::vec4 _v2) {
		v0 = _v0;
		v1 = _v1;
		v2 = _v2;
	}

	void setNormal(glm::vec3 _normal) {
		normal = _normal;
	}

	void setColor(glm::vec3 _color) {
		color = _color;
	}

	std::string getMaterial() {
		return material;
	}

	void setMaterial(std::string _material) {
		material = _material;
	}

private:
	glm::vec4 v0, v1, v2;
	glm::vec3 color;
	glm::vec3 normal;
	float brightness;

	std::string material = "DIFFUSE";
};


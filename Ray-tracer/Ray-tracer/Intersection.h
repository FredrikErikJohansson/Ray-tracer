#pragma once

#include "Triangle.h"
#include "Sphere.h"

class Intersection {
public:
	Intersection() :  R(nullptr), T(nullptr)
	{
	};

	~Intersection();

	void destroy();

	Triangle triangle;
	Sphere sphere;
	glm::vec3 point = glm::vec3(0.0f);
	std::string closest = "";

	Intersection *R;
	Intersection *T;
};

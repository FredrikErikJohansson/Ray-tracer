#pragma once

#include "Triangle.h"
#include "Sphere.h"

class Intersection {
public:
	Intersection(Intersection* _parent) : Parent(_parent), R(nullptr), T(nullptr)
	{
	};

	~Intersection();

	void destroy() {
		if (this) {
			this->R->destroy();
			this->T->destroy();
			delete this;
		}
	}

	float radiance = 0.0f;
	float importance = 1.0f;
	Triangle triangle;
	Sphere sphere;
	glm::vec3 point = glm::vec3(999.9f, 999.9f, 999.9f);
	std::string closest = "";

	Intersection *R;
	Intersection *T;
	Intersection *Parent;
};

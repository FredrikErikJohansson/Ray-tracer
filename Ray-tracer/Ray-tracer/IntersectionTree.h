#pragma once

#include "Triangle.h"
#include "Sphere.h"

struct Intersection {

	float radiance = 0.0f;
	float importance = 1.0f;
	glm::vec3 color = glm::vec3(0.0f, 0.0f, 0.0f);
	Triangle triangle;
	Sphere sphere;
	glm::vec3 point = glm::vec3(999.9f, 999.9f, 999.9f);
	std::string closest = "";
	int triHits = 0;
	int sphHits = 0;

	Intersection *R;
	Intersection *T;
	Intersection *Parent;
};

class IntersectionTree
{
public:
	IntersectionTree();
	~IntersectionTree();

private:
	

	void destroy_tree(Intersection *leaf);
	Intersection* root;
};


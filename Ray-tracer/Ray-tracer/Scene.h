#pragma once

#include <cmath>
#include <iostream>
#include <list>

#include "Triangle.h"
#include "Sphere.h"
#include "Ray.h"

struct TriangleIntersection {
	Triangle triangle;
	glm::vec3 point;
};

struct SphereIntersection {
	Sphere sphere;
	glm::vec3 point;
};

class Scene
{
public:
	Scene();
	~Scene();

	//something like this
	//Triangle& getIntersections(Ray ray);

	std::list<TriangleIntersection> triangleIntersections(Ray ray) const;
	std::list<SphereIntersection> sphereIntersections(Ray ray) const;

	void createScene();

private:
	Triangle triangles[24];
	Sphere spheres[1];
};


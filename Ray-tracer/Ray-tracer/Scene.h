#pragma once

#include <cmath>
#include <iostream>
#include <list>

#include "Triangle.h"
#include "Sphere.h"
#include "Ray.h"
#include "Tetrahedron.h"

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

	std::list<TriangleIntersection> triangleIntersections(Ray ray) const;
	std::list<SphereIntersection> sphereIntersections(Ray ray) const;

	bool visibilityTest(Ray shadowRay, std::string type);
	void createScene();

private:

	//The room is 24 triangles
	//Tetrahedron is 4 triangles
	int triangleAmount = 28;
	int tetrahedronTriangleAmount = 4;
	int sceneTriangles = 24;

	Tetrahedron tetrahedron;
	Triangle triangles[28];

	Sphere spheres[1];
};


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
	glm::vec3 point = glm::vec3(999.9f, 999.9f, 999.9f);
	int n_hits = 0;
};

struct SphereIntersection {
	Sphere sphere;
	glm::vec3 point = glm::vec3(999.9f, 999.9f, 999.9f);
	int n_hits = 0;
};

class Scene
{
public:
	Scene();
	~Scene();

	TriangleIntersection triangleIntersections(Ray ray) const;
	SphereIntersection sphereIntersections(Ray ray) const;

	bool isVisible(Ray shadowRay) const;
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


#pragma once

#include <cmath>
#include <iostream>
#include <list>

#include "Triangle.h"
#include "Sphere.h"
#include "Ray.h"
#include "Tetrahedron.h"
#include "IntersectionTree.h"

class Scene
{
public:
	Scene();
	~Scene();

	bool isVisible(Ray shadowRay) const;

	void createScene();

	glm::vec3 getIntersection(Ray ray, Intersection* root) const;
	Ray getReflection(Ray ray, Intersection* leaf) const;
	Ray getRefraction(Ray ray, Intersection* leaf) const;

private:

	//The room is 24 triangles
	//Tetrahedron is 4 triangles
	int triangleAmount = 28;
	int tetrahedronTriangleAmount = 4;
	int sceneTriangles = 24;

	Tetrahedron tetrahedron;
	Triangle triangles[30];

	Sphere spheres[3];
};


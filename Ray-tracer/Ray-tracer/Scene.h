#pragma once

#include <cmath>
#include <iostream>

#include "Triangle.h"
#include "Ray.h"
#include "Tetrahedron.h"

class Scene
{
public:
	Scene();
	~Scene();

	//something like this
	Triangle getIntersectedTriangle(Ray ray);

	void createScene();

private:
	//The room is 24 triangles
	//Tetrahedron is 4 triangles
	int triangleAmount = 28;
	int tetrahedronTriangleAmount = 4;
	int sceneTriangles = 24;

	Tetrahedron tetrahedron;
	Triangle triangles[28];
};


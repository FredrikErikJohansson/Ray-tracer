#pragma once

#include <cmath>
#include <iostream>

#include "Triangle.h"
#include "Ray.h"

class Scene
{
public:
	Scene();
	~Scene();

	//something like this
	Triangle getIntersectedTriangle(Ray ray);

	void createScene();

private:
	Triangle triangles[24];
};


#pragma once

#include <cmath>

#include "Triangle.h"
#include "Ray.h"

class Scene
{
public:
	Scene();
	~Scene();

	//something like this
	//void getIntersection();

	void createScene();

private:
	Triangle triangles[24];
};


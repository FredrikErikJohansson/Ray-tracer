#pragma once

#include <cmath>

#include "Triangle.h"

class Scene
{
public:
	Scene();
	~Scene();

	void createScene();

private:
	Triangle triangles[24];
};


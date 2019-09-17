#pragma once

#include "Vertex.h"

class Ray
{
public:
	Ray();
	~Ray();

private:
	Vertex startPoint;
	Vertex endPoint;
};


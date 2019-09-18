#pragma once

#include "Vertex.h"
#include "ColorDbl.h"

class Ray
{
public:
	Ray();
	Ray(Vertex _startPoint, Vertex _endPoint) {
		startPoint = _startPoint;
		endPoint = _endPoint;
	}
	~Ray();

private:
	Vertex startPoint;
	Vertex endPoint;
	ColorDbl color;
};


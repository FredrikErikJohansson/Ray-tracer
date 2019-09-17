#pragma once

#include "Vertex.h"
#include "ColorDbl.h"
#include "Direction.h"
#include "Ray.h"

class Triangle
{
public:
	Triangle();
	~Triangle();

	void rayIntersection(Ray arg) {
		//MÖLLER-trumbore
	}

	void setVertices(Vertex _v0, Vertex _v1, Vertex _v2) {
		v0 = _v0;
		v1 = _v1;
		v2 = _v2;
	}

	void setNormal(Direction _normal) {
		normal = _normal;
	}


private:
	Vertex v0, v1, v2;
	ColorDbl color;
	Direction normal;
};


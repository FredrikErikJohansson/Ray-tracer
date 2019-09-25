#pragma once

#include <cmath>
#include <iostream>
#include <math.h>
#include "Triangle.h"
#include "Ray.h"

class Tetrahedron
{
public:
	Tetrahedron();
	Tetrahedron(float _a, float _b, float _c, float _sideLength);
	~Tetrahedron();

	void setTetrahedronVertecies();
	void calcNormals();

	void createTetrahedron();
	Triangle getTetrahedronTriangles(int ind);

private: 
	Triangle tetrahedronTriangles[4];
	float a, b, c;
	float sideLength;


	glm::vec4 v0, v1, v2, v3; //Vertecies
	glm::vec3 nA, nB, nC, nD; //triangle normals 
};


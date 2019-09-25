#pragma once

#include <cmath>
#include <iostream>

#include "Triangle.h"
#include "Ray.h"

class Tetrahedron
{
public:
	Tetrahedron();
	Tetrahedron(int _a, int _b, int _c, float _sideLength);
	~Tetrahedron();

	void setVertecies();
	void calcNormals();

	void createTetrahedron();
	Triangle getTetrahedronTriangles(int ind);

private: 
	Triangle tetrahedronTriangles[4];
	int a, b, c;
	float sideLength;


	glm::vec4 v0, v1, v2, v3;
	glm::vec3 nA, nB, nC, nD; //triangle normals 
};


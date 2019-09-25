#include "Tetrahedron.h"



void Tetrahedron::createTetrahedron() {
	tetrahedronTriangles[0].setVertices(v0, v1, v2);
	tetrahedronTriangles[1].setVertices(v0, v3, v1);
	tetrahedronTriangles[2].setVertices(v0, v2, v3);
	tetrahedronTriangles[3].setVertices(v1, v3, v2);

	tetrahedronTriangles[0].setColor(glm::vec3(1, 0.5, 0));
	tetrahedronTriangles[1].setColor(glm::vec3(1, 0.5, 0));
	tetrahedronTriangles[2].setColor(glm::vec3(1, 0.5, 0));
	tetrahedronTriangles[3].setColor(glm::vec3(1, 0.5, 0));

	tetrahedronTriangles[0].setNormal(nA);
	tetrahedronTriangles[1].setNormal(nB);
	tetrahedronTriangles[2].setNormal(nC);
	tetrahedronTriangles[3].setNormal(nD);
	std::cout << "Tetrahedron created\n";
}

Triangle Tetrahedron::getTetrahedronTriangles(int ind) {
	return tetrahedronTriangles[ind];
}

Tetrahedron::Tetrahedron()
{
	a = 10;
	b = 2;
	c = 0;
	sideLength = 2.0f;
}

Tetrahedron::Tetrahedron(int _a, int _b, int _c, float _sideLength)
{
	a = _a;
	b = _b;
	c = _c;
	sideLength = _sideLength;
}

Tetrahedron::~Tetrahedron()
{
}

void Tetrahedron::setVertecies() {
	v0 = glm::vec4(a, b, c, 1);
	v1 = glm::vec4(a, b + sideLength / 2, c + (3 * sideLength*sideLength) / 4, 1);
	v2 = glm::vec4(a, b + sideLength, c, 1);
	v3 = glm::vec4(a + (3*sideLength*sideLength)/4, b + sideLength/2, c + sideLength/2, 1);
}

void Tetrahedron::calcNormals() {
	nA = glm::normalize(glm::cross(glm::vec3(v1 - v0), glm::vec3(v2 - v0)));
	nB = glm::normalize(glm::cross(glm::vec3(v3 - v0), glm::vec3(v1 - v0)));
	nC = glm::normalize(glm::cross(glm::vec3(v2 - v0), glm::vec3(v3 - v0)));
	nD = glm::normalize(glm::cross(glm::vec3(v3 - v1), glm::vec3(v2 - v1)));
}


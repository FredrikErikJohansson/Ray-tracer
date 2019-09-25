#include "Tetrahedron.h"



void Tetrahedron::createTetrahedron() {
	
	//Set the vertecies in the tetrahedron.
	setTetrahedronVertecies();

	//Create the triangles of the tetrahedron.
	tetrahedronTriangles[0].setVertices(v0, v2, v1);
	tetrahedronTriangles[1].setVertices(v0, v3, v2);
	tetrahedronTriangles[2].setVertices(v0, v1, v3);
	tetrahedronTriangles[3].setVertices(v1, v2, v3);

	//Set the color of the tetrahedron.
	tetrahedronTriangles[0].setColor(glm::vec3(1, 0.5, 0));
	tetrahedronTriangles[1].setColor(glm::vec3(1, 0.5, 0));
	tetrahedronTriangles[2].setColor(glm::vec3(1, 0.5, 0));
	tetrahedronTriangles[3].setColor(glm::vec3(1, 0.5, 0));

	//Calculate the normal vectors of the triangles of the tetrahedron.
	calcNormals();

	//Set the normals 
	tetrahedronTriangles[0].setNormal(nA);
	tetrahedronTriangles[1].setNormal(nB);
	tetrahedronTriangles[2].setNormal(nC);
	tetrahedronTriangles[3].setNormal(nD);
}

//Return a tetrahedron triangle
Triangle Tetrahedron::getTetrahedronTriangles(int ind) {
	return tetrahedronTriangles[ind];
}

//Default constructor
Tetrahedron::Tetrahedron()
{
	a = 5.0f;
	b = -4.0f;
	c = -2.0f;
	sideLength = 2.0f;
}

//Copy constructor
Tetrahedron::Tetrahedron(float _a, float _b, float _c, float _sideLength)
{
	a = _a;
	b = _b;
	c = _c;
	sideLength = _sideLength;
}

Tetrahedron::~Tetrahedron()
{
}

//Set the vertecies in the tetrahedron.
void Tetrahedron::setTetrahedronVertecies() {
	v0 = glm::vec4(a, b, c, 1);
	v1 = glm::vec4(a + (3.0f*pow(sideLength,2.0f))/4.0f , b + sideLength/2.0f ,c , 1);
	v2 = glm::vec4(a, b + sideLength, c, 1);
	v3 = glm::vec4(a + (3.0f*pow(sideLength, 2.0f))/8.0f, b + sideLength/2.0f, c + (3.0f * pow(sideLength, 2.0f)) / 4.0f, 1);
}

//Calculate the normal vectors of the triangles of the tetrahedron.
void Tetrahedron::calcNormals() {
	nA = glm::normalize(glm::cross(glm::vec3(v2 - v0), glm::vec3(v1 - v0)));
	nB = glm::normalize(glm::cross(glm::vec3(v3 - v0), glm::vec3(v2 - v0)));
	nC = glm::normalize(glm::cross(glm::vec3(v1 - v0), glm::vec3(v3 - v0)));
	nD = glm::normalize(glm::cross(glm::vec3(v2 - v1), glm::vec3(v3 - v1)));
}


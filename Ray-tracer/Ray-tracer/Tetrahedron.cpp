#include "Tetrahedron.h"

void Tetrahedron::createTetrahedron() {
	
	//Set the vertecies in the tetrahedron.
	setTetrahedronVertecies();

	//Create the triangles of the tetrahedron.
	tetrahedronTriangles[0].setVertices(v0, v1, v3);
	tetrahedronTriangles[1].setVertices(v1, v2, v3);
	tetrahedronTriangles[2].setVertices(v0, v3, v2);
	tetrahedronTriangles[3].setVertices(v0, v1, v2);

	//Set the color of the tetrahedron.
	tetrahedronTriangles[0].setColor(glm::vec3(1, 1, 1));
	tetrahedronTriangles[1].setColor(glm::vec3(1, 1, 1));
	tetrahedronTriangles[2].setColor(glm::vec3(1, 1, 1));
	tetrahedronTriangles[3].setColor(glm::vec3(1, 1, 1));

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
	v0 = glm::vec4(7.0f, 0.0f, -2.0f, 1.0f);
	sideLength = 2.0f;
}

//Copy constructor
Tetrahedron::Tetrahedron(glm::vec4 _v0, float _sideLength)
{
	v0 = _v0;
	sideLength = _sideLength;
}

Tetrahedron::~Tetrahedron()
{
}

//Set the vertecies in the tetrahedron.
void Tetrahedron::setTetrahedronVertecies() {
	/*
	v1 = glm::vec4(v0.x + (3.0f*pow(sideLength,2.0f))/4.0f , v0.y + sideLength/2.0f ,v0.z , 1);
	v2 = glm::vec4(v0.x, v0.y + sideLength, v0.z, 1);
	v3 = glm::vec4(v0.x + (3.0f*pow(sideLength, 2.0f))/8.0f, v0.y + sideLength/2.0f, v0.z + (3.0f * pow(sideLength, 2.0f)) / 4.0f, 1);*/
	v1 = glm::vec4(v0.x - sqrt(pow(sideLength, 2.0f) - pow(sideLength, 2.0f) / 4.0f), v0.y - sideLength / 2.0f, v0.z, 1.0f);
	v2 = glm::vec4(v0.x, v0.y - sideLength, v0.z, 1.0f);
	v3 = glm::vec4(v0.x, v0.y - sideLength / 2.0f, v0.z + sqrt(pow(sideLength, 2.0f) - pow(sideLength, 2.0f) / 4.0f), 1.0f);
}

//Calculate the normal vectors of the triangles of the tetrahedron.
void Tetrahedron::calcNormals() {
	nA = -glm::normalize(glm::cross(glm::vec3(v0 - v3), glm::vec3(v0 - v1)));
	nB = -glm::normalize(glm::cross(glm::vec3(v1 - v3), glm::vec3(v1 - v2)));
	nC = -glm::normalize(glm::cross(glm::vec3(v2 - v3), glm::vec3(v2 - v0)));
	nD = glm::normalize(glm::cross(glm::vec3(v0 - v2), glm::vec3(v0 - v1)));
}


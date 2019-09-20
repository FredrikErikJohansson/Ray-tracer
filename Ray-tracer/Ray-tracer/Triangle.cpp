#include "Triangle.h"


Triangle::Triangle()
{
}


Triangle::~Triangle()
{
}

bool Triangle::rayIntersection(Ray ray) {
	
	glm::vec3 rayStart = ray.getStartPoint();
	glm::vec3 rayEnd = ray.getEndPoint();
	glm::vec3 direction = ray.getDirection();
	

	glm::vec3 rayToVertex = rayStart - glm::vec3(v0);

	glm::vec3 edge01 = glm::vec3(v1) - glm::vec3(v0);
	glm::vec3 edge02 = glm::vec3(v2) - glm::vec3(v0);

	glm::vec3 P = glm::cross(direction, edge02);
	glm::vec3 Q = glm::cross(rayToVertex, edge01);

	double t = glm::dot(Q,edge02) / glm::dot(P,edge01);
	
	if (t > DBL_EPSILON && t < DBL_MAX) return true;

	return false;
}

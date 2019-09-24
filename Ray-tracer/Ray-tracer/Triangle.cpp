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
	glm::vec3 direction = glm::normalize(ray.getDirection());
	float t, u, v;

	glm::vec3 rayToVertex = rayStart - glm::vec3(v0);
	glm::vec3 edge01 = glm::vec3(v1) - glm::vec3(v0);
	glm::vec3 edge02 = glm::vec3(v2) - glm::vec3(v0);

	glm::vec3 P = glm::cross(direction, edge02);
	glm::vec3 Q = glm::cross(rayToVertex, edge01);

	t = glm::dot(Q, edge02) / glm::dot(P, edge01);
	u = glm::dot(P, rayToVertex) / glm::dot(P, edge01);
	v = glm::dot(Q, direction) / glm::dot(P, edge01);

	if (u < 0 || u > 1) return false;
	if (v < 0 || v > 1) return false;
	if (u + v > 1) return false;

	glm::vec3 currentHit = (1 - u - v)*v0 + u * v1 + v * v2;
	glm::vec3 shadowRay = glm::vec3(5, 0, 4) - currentHit;
	float angle = glm::dot(shadowRay, this->normal) / (glm::length(shadowRay)*glm::length(this->normal));
	this->brightness = angle;

	if (t > DBL_EPSILON && t < DBL_MAX) return true;

	return false;
}

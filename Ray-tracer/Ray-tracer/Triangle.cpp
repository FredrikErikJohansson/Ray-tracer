#include "Triangle.h"
#include <string>


Triangle::Triangle()
{
}


Triangle::~Triangle()
{
}

 glm::vec3 Triangle::getColor()  {
	return color;
}

 glm::vec3 Triangle::getNormal()  {
	return glm::normalize(normal);
}

 float Triangle::getBrightness()  {
	return brightness;
}

 Material Triangle::getMaterial()  {
	return material;
}

void Triangle::setVertices(glm::vec4 _v0, glm::vec4 _v1, glm::vec4 _v2) {
	v0 = _v0;
	v1 = _v1;
	v2 = _v2;
}

void Triangle::setNormal(glm::vec3 _normal) {
	normal = _normal;
}

void Triangle::setColor(glm::vec3 _color) {
	color = _color;
}

void Triangle::setMaterial(Material& _material) {
	material = _material;
}

bool Triangle::rayIntersection(Ray ray, glm::vec3 &intersection) {
	
	glm::vec3 rayStart = ray.getStartPoint();
	glm::vec3 rayEnd = ray.getEndPoint();
	glm::vec3 direction = glm::normalize(ray.getDirection());
	float t, u, v;

	glm::vec3 rayToVertex = rayStart - glm::vec3(v0);
	glm::vec3 edge01 = glm::vec3(v1) - glm::vec3(v0);
	glm::vec3 edge02 = glm::vec3(v2) - glm::vec3(v0);

	glm::vec3 P = glm::cross(direction, edge02);
	glm::vec3 Q = glm::cross(rayToVertex, edge01);
	u = glm::dot(P, rayToVertex) / glm::dot(P, edge01);
	v = glm::dot(Q, direction) / glm::dot(P, edge01);

	if (u < 0 || u > 1) return false;
	if (v < 0 || v > 1) return false;
	if (u + v > 1) return false;

	glm::vec3 currentHit = (1 - u - v)*v0 + u * v1 + v * v2;

	//Check if triangle is infront of ray
	if (glm::dot(ray.getDirection(), this->normal) > 0.0f) return false;

	//Make visibility test (if not visible set brightness to 0)
	//traceShadowRay() which calls rayIntersection
	float xx = ((float)rand() / RAND_MAX) * (6 - 4) + 4;
	float yy = ((float)rand() / RAND_MAX) * (1 + 1) - 1;

	//Ray shadowRay = Ray(currentHit, glm::vec3(xx, yy, 5));
	//float shadowAngle = glm::dot(shadowRay.getDirection(), this->getNormal()) / (glm::length(shadowRay.getDirection())*glm::length(this->getNormal()));
	//this->brightness = shadowAngle;

	t = glm::dot(Q, edge02) / glm::dot(P, edge01);

	//Check with distance if we got a hit
	if (t < FLT_EPSILON || t > 1000.0f) return false;

	intersection = rayStart + direction * t;

	return true;
}

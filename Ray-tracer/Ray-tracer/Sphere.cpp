#include "Sphere.h"



Sphere::Sphere()
{
}


Sphere::~Sphere()
{
}

bool Sphere::rayIntersection(Ray ray, glm::vec3 &intersection) {
	glm::vec3 rayStart = ray.getStartPoint();
	glm::vec3 direction = glm::normalize(ray.getDirection());
	float b, c, d1, d2, d, x;

	b = glm::dot(2.0f*direction, (rayStart - this->center));
	c = glm::dot((rayStart - this->center), (rayStart - this->center)) - pow(this->radius, 2.0f);

	x = pow((b / 2.0f), 2.0f) - c;

	if (x < 0) return false;

	d1 = -(b / 2.0f) + sqrt(x);
	d2 = -(b / 2.0f) - sqrt(x);
	
	if (d1 < 0) d = d2;
	else if (d2 < 0) d = d1;
	else if (d1 < d2) d = d1;
	else d = d2;

	//Check if d is a number?
	if (d < FLT_EPSILON || d > 1000.0f) return false;
	intersection = rayStart + direction * d;

	glm::vec3 normal = glm::normalize(intersection - this->center);

	float hitAngle = acos(glm::dot(intersection, normal) / (glm::length(intersection)*glm::length(normal)));

	//Check if triangle is infront of ray
	if (hitAngle > 45.0f) return false;

	glm::vec3 shadowRay = glm::vec3(5, 0, 4) - intersection;
	float shadowAngle = glm::dot(shadowRay, normal) / (glm::length(shadowRay)*glm::length(normal));

	if (shadowAngle < 0.0f) this->brightness = 0.0f;
	else this->brightness = shadowAngle;

	return true;
}
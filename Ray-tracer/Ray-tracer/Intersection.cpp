#include "Intersection.h"



Intersection::Intersection()
{
}


Intersection::~Intersection()
{
}

int Intersection::getTriHits() {
	return triHits;
}

int Intersection::getSphHits() {
	return sphHits;
}

glm::vec3 Intersection::getPoint() {
	return point;
}

std::string Intersection::getClosest() {
	return closest;
}

Triangle& Intersection::getTriangle() {
	return triangle;
}

Sphere Intersection::getSphere() {
	return sphere;
}

void Intersection::setTriangle(Triangle _triangle) {
	triangle = _triangle;
}

void Intersection::setSphere(Sphere _sphere) {
	sphere = _sphere;
}

void Intersection::setClosest(std::string _closest) {
	closest = _closest;
}
void Intersection::setPoint(glm::vec3 _point) {
	point = _point;
}

void Intersection::incrementTriHits() {
	triHits++;
}

void Intersection::incrementSphHits() {
	sphHits++;
}

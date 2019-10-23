#include "Sphere.h"



Sphere::Sphere()
{
}


Sphere::~Sphere()
{
}

float Sphere::getBrightness() {
	return brightness;
}

glm::vec3 Sphere::getColor() {
	return color;
}

glm::vec3 Sphere::getCenter() {
	return center;
}

Material Sphere::getMaterial() {
	return material;
}

glm::vec3 Sphere::getNormal(glm::vec3 point) {
	return glm::normalize(point - this->center);
}


void Sphere::setColor(glm::vec3 _color) {
	color = _color;
}

void Sphere::setCenter(glm::vec3 _center) {
	center = _center;
}

void Sphere::setRadius(float _radius) {
	radius = _radius;
}

void Sphere::setMaterial(Material _material) {
	material = _material;
}

bool Sphere::rayIntersection(Ray ray, glm::vec3 &intersection) {
	glm::vec3 rayStart = ray.getStartPoint();
	glm::vec3 direction = ray.getDirection();
	float b, c, d1, d2, d, x;

	b = glm::dot(2.0f*direction, (rayStart - this->center));
	c = glm::dot((rayStart - this->center), (rayStart - this->center)) - pow(this->radius, 2.0f);

	x = pow((b / 2.0f), 2.0f) - c;

	if (x < FLT_EPSILON) return false;

	d1 = -(b / 2.0f) + sqrt(x);
	d2 = -(b / 2.0f) - sqrt(x);
	
	if (d1 <= 0 && d2 <= 0) return false;
	else if (d1 < 0) d = d2;
	else if (d2 < 0) d = d1;
	else if (d1 < d2) d = d1;
	else d = d2;

	//Check with distance if we got a hit
	if (d < FLT_EPSILON || d > 1000.0f) return false;
	intersection = rayStart + direction * d;

	glm::vec3 normal = glm::normalize(intersection - this->center);

	//Check if sphere is infront of ray
	if (glm::dot(ray.getDirection(), normal) > 0.0f) return false;

	//float xx = ((float)rand() / RAND_MAX) * (6 - 4) + 4;
	//float yy = ((float)rand() / RAND_MAX) * (1 + 1) - 1;

	//Ray shadowRay = Ray(intersection, glm::vec3(xx, yy, 5));
	//float shadowAngle = glm::dot(shadowRay.getDirection(), normal);

	//May not be needed
	//if (shadowAngle < 0) this->brightness = 0.0f;
	//else this->brightness = shadowAngle;
	//this->brightness = shadowAngle;

	return true;
}
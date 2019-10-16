#pragma once

#include "Triangle.h"
#include "Sphere.h"

class Intersection
{
public:
	Intersection();
	~Intersection();

	Intersection *Left;
	Intersection *Right;
	Intersection *Parent;

	int getTriHits();
	int getSphHits();
	glm::vec3 getPoint();
	std::string getClosest();
	Triangle& getTriangle();
	Sphere getSphere();

	void setTriangle(Triangle _triangle);
	void setSphere(Sphere _sphere);
	void setClosest( std::string _closest);
	void setPoint(glm::vec3 _point);

	void incrementTriHits();
	void incrementSphHits();

private:
	Triangle triangle;
	Sphere sphere;
	glm::vec3 point = glm::vec3(999.9f, 999.9f, 999.9f);
	std::string closest = "";
	int triHits = 0;
	int sphHits = 0;
	float radiance;
};


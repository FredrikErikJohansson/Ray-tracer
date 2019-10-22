#pragma once

#include <math.h>
#include <string>
#include <iostream>

#include "glm/glm.hpp"
#include "Ray.h"
#include "Material.h"

class Sphere
{
public:
	Sphere();
	~Sphere();

	bool rayIntersection(Ray ray, glm::vec3&);

	float getBrightness();
	glm::vec3 getColor();
	glm::vec3 getCenter();
	Material getMaterial();
	glm::vec3 getNormal(glm::vec3 point);

	void setColor(glm::vec3 _color);
	void setCenter(glm::vec3 _center);
	void setRadius(float _radius);
	void setMaterial(Material _material);

private:
	glm::vec3 center;
	glm::vec3 color;
	float radius;
	float brightness;
	Material material;
};


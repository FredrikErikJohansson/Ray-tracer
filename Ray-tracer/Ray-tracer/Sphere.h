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

	float getBrightness() const;
	glm::vec3 getColor() const;
	glm::vec3 getCenter() const;
	Material& getMaterial();

	void setColor(glm::vec3 _color);
	void setCenter(glm::vec3 _center);
	void setRadius(float _radius);

private:
	glm::vec3 center;
	glm::vec3 color;
	float radius;
	float brightness;
	Material material;
};


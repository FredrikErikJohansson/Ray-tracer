#pragma once

#include <iostream>
#include <math.h>

#include "glm/glm.hpp"
#include "Ray.h"
#include "Material.h"

class Triangle
{
public:
	Triangle();
	~Triangle();

	bool rayIntersection(Ray arg, glm::vec3&);

	glm::vec3 getColor() const;
	glm::vec3 getNormal() const;
	float getBrightness() const;
	Material& getMaterial();

	void setVertices(glm::vec4 _v0, glm::vec4 _v1, glm::vec4 _v2);
	void setNormal(glm::vec3 _normal);
	void setColor(glm::vec3 _color);

private:
	glm::vec4 v0, v1, v2;
	glm::vec3 color;
	glm::vec3 normal;
	float brightness;

	Material material;
};


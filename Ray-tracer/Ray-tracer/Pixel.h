#pragma once

#include "Ray.h"

class Pixel
{
public:
	Pixel();
	~Pixel();

	glm::vec3 getColor() const;
	void setColor(double _red, double _green, double _blue);
	void setColor(glm::vec3 _color);

private:
	glm::vec3 color;
	Ray ray;
};


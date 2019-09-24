#pragma once

#include "Ray.h"

class Pixel
{
public:
	Pixel();
	~Pixel();

	glm::vec3 getColor(){
		return color;
	}

	void setColor(double _red, double _green, double _blue) {
		color = glm::vec3(_red, _green, _blue);
	}

	void setColor(glm::vec3 _color) {
		color = _color;
	}

private:
	glm::vec3 color;
	Ray ray;
};


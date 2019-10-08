#include "Pixel.h"


Pixel::Pixel()
{
}


Pixel::~Pixel()
{
}

glm::vec3 Pixel::getColor() const {
	return color;
}

void Pixel::setColor(double _red, double _green, double _blue) {
	color = glm::vec3(_red, _green, _blue);
}

void Pixel::setColor(glm::vec3 _color) {
	color = _color;
}
#include "Ray.h"


Ray::Ray()
{
}

Ray::Ray(glm::vec4 _startPoint, glm::vec4 _endPoint) {
	startPoint = _startPoint;
	endPoint = _endPoint;
	direction = glm::normalize(_endPoint - _startPoint);
	length = glm::distance(glm::vec3(_endPoint),glm::vec3(_startPoint));
}
Ray::Ray(glm::vec3 _startPoint, glm::vec3 _endPoint) {
	startPoint = glm::vec4(_startPoint, 1);
	endPoint = glm::vec4(_endPoint, 1);
	direction = glm::normalize(_endPoint - _startPoint);
	length = glm::distance(_endPoint,_startPoint);
}

Ray::~Ray()
{
}

glm::vec4 Ray::getStartPoint() const {
	return startPoint;
}

glm::vec4 Ray::getEndPoint() const {
	return endPoint;
}

glm::vec3 Ray::getDirection() const {
	return direction;
}

float Ray::getLength() const {
	return length;
}

int Ray::getdepth() const {
	return depth;
}

void Ray::operator++(int) {
	depth++;
}
void Ray::operator--(int) {
	depth--;
}
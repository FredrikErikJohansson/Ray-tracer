#pragma once

#include "glm/glm.hpp"

class Ray
{
public:
	Ray();
	Ray(glm::vec4 _startPoint, glm::vec4 _endPoint) {
		startPoint = _startPoint;
		endPoint = _endPoint;
		direction = glm::normalize(_endPoint - _startPoint);
		length = glm::length(_endPoint - _startPoint);
	}
	Ray(glm::vec3 _startPoint, glm::vec3 _endPoint) {
		startPoint = glm::vec4(_startPoint, 1);
		endPoint = glm::vec4(_endPoint, 1);
		direction = glm::normalize(_endPoint - _startPoint);
		length = glm::length(_endPoint - _startPoint);
	}
	~Ray();

	glm::vec4 getStartPoint() {
		return startPoint;
	}

	glm::vec4 getEndPoint() {
		return endPoint;
	}

	glm::vec3 getDirection() {
		return direction;
	}

	float getLength() {
		return length;
	}

private:
	glm::vec4 startPoint;
	glm::vec4 endPoint;
	glm::vec3 direction;
	glm::vec3 color;
	float length;
};


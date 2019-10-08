#pragma once

#include "glm/glm.hpp"

class Ray
{
public:
	Ray();
	Ray(glm::vec4 _startPoint, glm::vec4 _endPoint);
	Ray(glm::vec3 _startPoint, glm::vec3 _endPoint);
	~Ray();

	glm::vec4 getStartPoint() const;
	glm::vec4 getEndPoint() const;
	glm::vec3 getDirection() const;
	float getLength() const;
	int getdepth() const;

	void operator++(int);
	void operator--(int);

private:
	glm::vec4 startPoint;
	glm::vec4 endPoint;
	glm::vec3 direction;
	glm::vec3 color;
	float length;
	int depth;
};


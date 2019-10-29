#pragma once

#define GLM_ENABLE_EXPERIMENTAL

#include <math.h>
#include <iostream>
#include <list>
#include <random>


#include "Triangle.h"
#include "Sphere.h"
#include "Ray.h"
#include "Tetrahedron.h"
#include "Intersection.h"
#include "glm/gtx/rotate_vector.hpp"

static std::default_random_engine GENERATOR;
static std::uniform_real_distribution<float> DISTR(0.0, 1.0);

class Scene
{
public:
	Scene();
	~Scene();

	bool isVisible(Ray ray) const;

	void createScene();
	float uniformRand();
	float randMinMax(const float &min, const float &max);

	glm::vec3 calculateDirectLight(Intersection* root, bool&);

	Ray getRandomRay(Ray ray, Intersection* leaf);
	glm::vec3 getIntersection(Ray ray, Intersection* root, bool&);
	template <class T>
	glm::vec3 getLightContribution(Ray, Intersection*, T, bool&);
	Ray getReflection(Ray ray, Intersection* leaf, bool&);
	Ray getRefraction(Ray ray, Intersection* leaf, bool&);
	

private:

	//The room is 24 triangles
	//Tetrahedron is 4 triangles
	int triangleAmount = 30;
	int tetrahedronTriangleAmount = 4;
	int sceneTriangles = 26;

	glm::vec3 lightBrightness = glm::vec3(5.0f);

	Tetrahedron tetrahedron;
	Triangle triangles[30];

	Sphere spheres[3];
};


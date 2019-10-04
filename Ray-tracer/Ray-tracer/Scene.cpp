#include "Scene.h"


Scene::Scene()
{
	//Create the tetrahedron
	tetrahedron.createTetrahedron();
}

void Scene::createScene() {
	
	//Floor vertices
	triangles[0].setVertices(glm::vec4(-3, 0, -5, 1), glm::vec4(5, 0, -5, 1), glm::vec4(0, -6, -5, 1));
	triangles[1].setVertices(glm::vec4(0, -6, -5, 1), glm::vec4(5, 0, -5, 1), glm::vec4(10, -6, -5, 1));
	triangles[2].setVertices(glm::vec4(10, -6, -5, 1), glm::vec4(5, 0, -5, 1), glm::vec4(13, 0, -5, 1));
	triangles[3].setVertices(glm::vec4(13, 0, -5, 1), glm::vec4(5, 0, -5, 1), glm::vec4(10, 6, -5, 1));
	triangles[4].setVertices(glm::vec4(10, 6, -5, 1), glm::vec4(5, 0, -5, 1), glm::vec4(0, 6, -5, 1));
	triangles[5].setVertices(glm::vec4(0, 6, -5, 1), glm::vec4(5, 0, -5, 1), glm::vec4(-3, 0, -5, 1));

	//Floor colors
	triangles[0].setColor(glm::vec3(1, 1, 1));
	triangles[1].setColor(glm::vec3(1, 1, 1));
	triangles[2].setColor(glm::vec3(1, 1, 1));
	triangles[3].setColor(glm::vec3(1, 1, 1));
	triangles[4].setColor(glm::vec3(1, 1, 1));
	triangles[5].setColor(glm::vec3(1, 1, 1));

	//Floor normals
	triangles[0].setNormal(glm::vec3(0, 0, 1));
	triangles[1].setNormal(glm::vec3(0, 0, 1));
	triangles[2].setNormal(glm::vec3(0, 0, 1));
	triangles[3].setNormal(glm::vec3(0, 0, 1));
	triangles[4].setNormal(glm::vec3(0, 0, 1));
	triangles[5].setNormal(glm::vec3(0, 0, 1));

	//Walls vertices (left)
	triangles[6].setVertices(glm::vec4(-3, 0, -5, 1), glm::vec4(-3, 0, 5, 1), glm::vec4(0, 6, -5, 1));
	triangles[7].setVertices(glm::vec4(0, 6, -5, 1), glm::vec4(-3, 0, 5, 1), glm::vec4(0, 6, 5, 1));
	triangles[8].setVertices(glm::vec4(0, 6, -5, 1), glm::vec4(0, 6, 5, 1), glm::vec4(10, 6, -5, 1));
	triangles[9].setVertices(glm::vec4(10, 6, -5, 1), glm::vec4(0, 6, 5, 1), glm::vec4(10, 6, 5, 1));
	triangles[10].setVertices(glm::vec4(10, 6, -5, 1), glm::vec4(10, 6, 5, 1), glm::vec4(13, 0, -5, 1));
	triangles[11].setVertices(glm::vec4(13, 0, -5, 1), glm::vec4(10, 6, 5, 1), glm::vec4(13, 0, 5, 1));

	//Walls colors (left)
	triangles[6].setColor(glm::vec3(1, 0, 0));
	triangles[7].setColor(glm::vec3(1, 0, 0));
	triangles[8].setColor(glm::vec3(0, 1, 0));
	triangles[9].setColor(glm::vec3(0, 1, 0));
	triangles[10].setColor(glm::vec3(0, 0, 1));
	triangles[11].setColor(glm::vec3(0, 0, 1));

	//Walls normals (left)
	triangles[6].setNormal(glm::vec3(2 / sqrt(5), -1 / sqrt(5), 0));
	triangles[7].setNormal(glm::vec3(2 / sqrt(5), -1 / sqrt(5), 0));
	triangles[8].setNormal(glm::vec3(0, -1, 0));
	triangles[9].setNormal(glm::vec3(0, -1, 0));
	triangles[10].setNormal(glm::vec3(-2 / sqrt(5), -1 / sqrt(5), 0));
	triangles[11].setNormal(glm::vec3(-2 / sqrt(5), -1 / sqrt(5), 0));

	//Walls vertices (right)
	triangles[12].setVertices(glm::vec4(13, 0, -5, 1), glm::vec4(13, 0, 5, 1), glm::vec4(10, -6, -5, 1));
	triangles[13].setVertices(glm::vec4(10, -6, -5, 1), glm::vec4(13, 0, 5, 1), glm::vec4(10, -6, 5, 1));
	triangles[14].setVertices(glm::vec4(0, -6, -5, 1), glm::vec4(0, -6, 5, 1), glm::vec4(10, -6, -5, 1));
	triangles[15].setVertices(glm::vec4(10, -6, -5, 1), glm::vec4(0, -6, 5, 1), glm::vec4(10, -6, 5, 1));
	triangles[16].setVertices(glm::vec4(0, -6, -5, 1), glm::vec4(0, -6, 5, 1), glm::vec4(-3, 0, -5, 1));
	triangles[17].setVertices(glm::vec4(-3, 0, -5, 1), glm::vec4(0, -6, 5, 1), glm::vec4(-3, 0, 5, 1));

	//Walls colors (right)
	triangles[12].setColor(glm::vec3(0.5, 0.5, 0));
	triangles[13].setColor(glm::vec3(0.5, 0.5, 0));
	triangles[14].setColor(glm::vec3(0, 0, 0.5));
	triangles[15].setColor(glm::vec3(0, 0, 0.5));
	triangles[16].setColor(glm::vec3(0.5, 0, 0.5));
	triangles[17].setColor(glm::vec3(0.5, 0, 0.5));

	//Walls normals (right)
	triangles[12].setNormal(glm::vec3(-2 / sqrt(5), 1 / sqrt(5), 0));
	triangles[13].setNormal(glm::vec3(-2 / sqrt(5), 1 / sqrt(5), 0));
	triangles[14].setNormal(glm::vec3(0, 1, 0));
	triangles[15].setNormal(glm::vec3(0, 1, 0));
	triangles[16].setNormal(glm::vec3(2 / sqrt(5), 1 / sqrt(5), 0));
	triangles[17].setNormal(glm::vec3(2 / sqrt(5), 1 / sqrt(5), 0));

	//Roof vertices
	triangles[18].setVertices(glm::vec4(-3, 0, 5, 1), glm::vec4(5, 0, 5, 1), glm::vec4(0, -6, 5, 1));
	triangles[19].setVertices(glm::vec4(0, -6, 5, 1), glm::vec4(5, 0, 5, 1), glm::vec4(10, -6, 5, 1));
	triangles[20].setVertices(glm::vec4(10, -6, 5, 1), glm::vec4(5, 0, 5, 1), glm::vec4(13, 0, 5, 1));
	triangles[21].setVertices(glm::vec4(13, 0, 5, 1), glm::vec4(5, 0, 5, 1), glm::vec4(10, 6, 5, 1));
	triangles[22].setVertices(glm::vec4(10, 6, 5, 1), glm::vec4(5, 0, 5, 1), glm::vec4(0, 6, 5, 1));
	triangles[23].setVertices(glm::vec4(0, 6, 5, 1), glm::vec4(5, 0, 5, 1), glm::vec4(-3, 0, 5, 1));

	//Roof colors
	triangles[18].setColor(glm::vec3(1, 1, 1));
	triangles[19].setColor(glm::vec3(1, 1, 1));
	triangles[20].setColor(glm::vec3(1, 1, 1));
	triangles[21].setColor(glm::vec3(1, 1, 1));
	triangles[22].setColor(glm::vec3(1, 1, 1));
	triangles[23].setColor(glm::vec3(1, 1, 1));

	//Roof normals
	triangles[18].setNormal(glm::vec3(0, 0, -1));
	triangles[19].setNormal(glm::vec3(0, 0, -1));
	triangles[20].setNormal(glm::vec3(0, 0, -1));
	triangles[21].setNormal(glm::vec3(0, 0, -1));
	triangles[22].setNormal(glm::vec3(0, 0, -1));
	triangles[23].setNormal(glm::vec3(0, 0, -1));
	
	//Get the triangles of the tetrahedron
	for (int i = 0; i < tetrahedronTriangleAmount; i++) {
		triangles[sceneTriangles + i] = tetrahedron.getTetrahedronTriangles(i);
	}

	//Tetrahedron
	/*
	glm::vec4 v0 = glm::vec4(8.0f, -3.0f, -2.0f, 1.0f);
	float sideLength = 2.0f;
	glm::vec4 v1 = glm::vec4(v0.x + (3.0f*pow(sideLength, 2.0f)) / 4.0f, v0.y + sideLength / 2.0f, v0.z, 1);
	glm::vec4 v2 = glm::vec4(v0.x, v0.y + sideLength, v0.z, 1);
	glm::vec4 v3 = glm::vec4(v0.x + (3.0f*pow(sideLength, 2.0f)) / 8.0f, v0.y + sideLength / 2.0f, v0.z + (3.0f * pow(sideLength, 2.0f)) / 4.0f, 1);
	glm::vec3 nA = glm::normalize(glm::cross(glm::vec3(v2 - v0), glm::vec3(v1 - v0)));
	glm::vec3 nB = glm::normalize(glm::cross(glm::vec3(v3 - v0), glm::vec3(v2 - v0)));
	glm::vec3 nC = glm::normalize(glm::cross(glm::vec3(v1 - v0), glm::vec3(v3 - v0)));
	glm::vec3 nD = glm::normalize(glm::cross(glm::vec3(v2 - v1), glm::vec3(v3 - v1)));
	//Create the triangles of the tetrahedron.
	triangles[24].setVertices(v0, v2, v1);
	triangles[25].setVertices(v0, v3, v2);
	triangles[26].setVertices(v0, v1, v3);
	triangles[27].setVertices(v1, v2, v3);

	//Set the color of the tetrahedron.
	triangles[24].setColor(glm::vec3(1, 0.5, 0));
	triangles[25].setColor(glm::vec3(1, 0.5, 0));
	triangles[26].setColor(glm::vec3(1, 0.5, 0));
	triangles[27].setColor(glm::vec3(1, 0.5, 0));

	//Set the normals 
	triangles[24].setNormal(nA);
	triangles[25].setNormal(nB);
	triangles[26].setNormal(nC);
	triangles[27].setNormal(nD);*/

	//Test
	/*triangles[24].setVertices(glm::vec4(10, -6, 4, 1), glm::vec4(5, 0, 4, 1), glm::vec4(13, 0, 4, 1));
	triangles[25].setVertices(glm::vec4(13, 0, 4, 1), glm::vec4(5, 0, 4, 1), glm::vec4(10, 6, 4, 1));
	triangles[24].setColor(glm::vec3(1, 1, 1));
	triangles[25].setColor(glm::vec3(1, 1, 1));
	triangles[24].setNormal(glm::vec3(0, 0, -1));
	triangles[25].setNormal(glm::vec3(0, 0, -1));*/

	//Sphere
	spheres[0].setCenter(glm::vec3(8, 2 , 0));
	spheres[0].setRadius(2.0f);
	spheres[0].setColor(glm::vec3(1, 0, 0));
	spheres[0].setMaterial("MIRROR");

	//DEBUGGING MIRROR
	/*for (int i = 14; i <= 15; i++)
	{
		triangles[i].setMaterial("MIRROR");
	}*/
}


Scene::~Scene()
{
}


TriangleIntersection Scene::triangleIntersections(Ray ray) const {
	TriangleIntersection ti;
	float minDistance = 1000.0f;
	for (Triangle triangle : triangles) {
		glm::vec3 intersection;
		if (triangle.rayIntersection(ray, intersection)) {
			ti.n_hits++;
			//Find the intersection with the lowest t.
			if (glm::length(intersection) < minDistance) {
				minDistance = glm::length(intersection);
				ti.triangle = triangle;
				ti.point = intersection + 0.001f * triangle.getNormal();
			}		
		}
	}
	//Mirror check
	/*if (ti.n_hits > 0 && ti.triangle.getMaterial() == "MIRROR") {
		//R = 2(N*L)N-L
		glm::vec3 L = ray.getDirection();
		glm::vec3 N = ti.triangle.getNormal();
		glm::vec3 R = 2.0f*glm::dot(N, L)*N - L;
		Ray reflectedRay = Ray(ti.point + 0.001f*N, R);
		ti = this->triangleIntersections(reflectedRay);
	}*/
	return ti;
};

SphereIntersection Scene::sphereIntersections(Ray ray) const {
	SphereIntersection si;
	si.n_hits = 0;
	float minDistance = 1000.0f;
	for (Sphere sphere : spheres) {
		glm::vec3 intersection;
		if(sphere.rayIntersection(ray, intersection)) {
			si.n_hits++;
			if (glm::length(intersection) < minDistance) {
				si.sphere = sphere;
				si.point = intersection + 0.001f * glm::normalize(si.point - sphere.getCenter());
			}
		}
	}
	
	//Mirror check
	/*if (si.n_hits > 0 && si.sphere.getMaterial() == "MIRROR") {
		//R = 2(N*L)N-L
		glm::vec3 L = ray.getDirection();
		glm::vec3 N = glm::normalize(si.point - si.sphere.getCenter());
		glm::vec3 R = 2.0f*glm::dot(N, L)*N - L;
		Ray reflectedRay = Ray(si.point + 0.001f*N, R);
		si = this->sphereIntersections(reflectedRay);
	}*/

	return si;
};

bool Scene::isVisible(Ray ray) const {
	glm::vec3 lastPoint = ray.getStartPoint();

	TriangleIntersection triangleIntersection = this->triangleIntersections(ray);
	SphereIntersection sphereIntersection = this->sphereIntersections(ray);

	if (sphereIntersection.n_hits > 0) return false;

	//Set to 6 because the lightsource is located in a point where all the roof triangles interconnect
	if (triangleIntersection.n_hits > 1) return false;

	return true;
}


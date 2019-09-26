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

	//Sphere
	spheres[0].setCenter(glm::vec3(8, 2 , 0));
	spheres[0].setRadius(2.0f);
	spheres[0].setColor(glm::vec3(1, 0, 0));

}


Scene::~Scene()
{
}


std::list<TriangleIntersection> Scene::triangleIntersections(Ray ray) const {
	std::list<TriangleIntersection> intersections = {};
	for (Triangle triangle : triangles) {
		TriangleIntersection ti;
		glm::vec3 intersection;
		if (triangle.rayIntersection(ray, intersection)) {
			ti.triangle = triangle;
			ti.point = intersection + 0.001f * triangle.getNormal();
			intersections.push_back(ti);
		}
	}

	//Sort intersections after first hit
	glm::vec3 rayStart = ray.getStartPoint();
	intersections.sort([&rayStart](const auto &a, const auto &b) {
		return glm::length(a.point - rayStart) < glm::length(b.point - rayStart);
	});
	return intersections;
};

std::list<SphereIntersection> Scene::sphereIntersections(Ray ray) const {
	std::list<SphereIntersection> intersectinons = {};
	for (Sphere sphere : spheres) {
		glm::vec3 intersection;
		SphereIntersection si;
		if(sphere.rayIntersection(ray, intersection)) {
			si.sphere = sphere;
			si.point = intersection + 0.001f * glm::normalize(si.point - sphere.getCenter());
			intersectinons.push_back(si);
		}
	}
	return intersectinons;
};

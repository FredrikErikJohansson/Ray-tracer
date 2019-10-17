#include "Scene.h"


Scene::Scene()
{
	//Create the tetrahedron
	tetrahedron.createTetrahedron();
}




Scene::~Scene()
{
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

	Material pureTransp;
	pureTransp.setType("TRANSPARENT");
	pureTransp.setN(1.5f);

	Material pureReflect;
	pureReflect.setType("MIRROR");

	triangles[24].setMaterial(pureTransp);
	triangles[25].setMaterial(pureTransp);
	triangles[26].setMaterial(pureTransp);
	triangles[27].setMaterial(pureTransp);

	//Sphere
	spheres[0].setCenter(glm::vec3(8, 2, 0));
	spheres[0].setRadius(2.0f);
	spheres[0].setColor(glm::vec3(1, 0, 0));
	spheres[0].setMaterial(pureReflect);

	//DEBUGGING MIRROR
	/*for (int i = 0; i <= 27; i++)
	{
		triangles[i].setMaterial(pureReflect);
	}*/
}

Intersection* Scene::getIntersection(Ray ray, Intersection* root) const {

	glm::vec3 intersection;
	float minDistance = 1000.0f;
	for (Triangle triangle : triangles) {
		if (triangle.rayIntersection(ray, intersection)) {
			root->triHits++;
			if (glm::length(intersection) < minDistance) {
				minDistance = glm::length(intersection);
				root->triangle = triangle;
				root->point = intersection;
				root->closest = "TRIANGLE";
			}
		}
	}
	for (Sphere sphere : spheres) {
		if (sphere.rayIntersection(ray, intersection)) {
			root->sphHits++;
			//Distance calculation between sphere & triangles are wrong (maybe)
			if (glm::length(intersection) < minDistance) {
				minDistance = glm::length(intersection);
				
				root->sphere = sphere;
				//isec.point = intersection + 0.001f * glm::normalize(intersection - sphere.getCenter());
				root->point = intersection + 0.001f * glm::normalize(intersection - sphere.getCenter());
				root->closest = "SPHERE";
			}
		}
	}

	if (ray.getdepth() < 6) {
		if (root->closest == "TRIANGLE") {
			if (root->triangle.getMaterial().getType() == "MIRROR") {

				root->R = new Intersection();
				root->R->Parent = root;
				root->R->R = nullptr;
				root->R->T = nullptr;

				ray = this->getReflection(ray, root);
				ray++;
				root = this->getIntersection(ray, root->R);
			}
			else if (root->triangle.getMaterial().getType() == "TRANSPARENT") {

				root->T = new Intersection();
				root->T->Parent = root;
				root->T->R = nullptr;
				root->T->T = nullptr;

				ray = this->getRefraction(ray, root);
				ray++;
				root = this->getIntersection(ray, root->T);
			}
		}
		else if (root->closest == "SPHERE") {
			if (root->sphere.getMaterial().getType() == "MIRROR") {

				root->R = new Intersection();
				root->R->Parent = root;
				root->R->R = nullptr;
				root->R->T = nullptr;

				ray = this->getReflection(ray, root);
				ray++;
				root = this->getIntersection(ray, root->R);
			}
			else if (root->sphere.getMaterial().getType() == "TRANSPARENT") {

				root->T = new Intersection();
				root->T->Parent = root;
				root->T->R = nullptr;
				root->T->T = nullptr;

				ray = this->getRefraction(ray, root);
				ray++;
				root = this->getIntersection(ray, root->T);
			}
		}
	}

	ray--;

	//Calculates the radiance of the root using Li=(Wr*Lr+Wt*Lt)/Wi
	if (root->R != nullptr && root->T != nullptr)
		root->radiance += ((root->R->radiance*root->R->importance) + (root->T->radiance*root->T->importance)) / root->importance;
	else if (root->R != nullptr)
		root->radiance += (root->R->radiance*root->R->importance) / root->importance;
	else if (root->T != nullptr)
		root->radiance += (root->T->radiance*root->T->importance) / root->importance;


	//Adds radiance from brightness
	if (root->closest == "TRIANGLE")
		root->radiance += root->triangle.getBrightness();
	else if (root->closest == "SPHERE")
		root->radiance += root->sphere.getBrightness();

	return root;
};

Ray Scene::getReflection(Ray ray, Intersection* leaf) const {
	glm::vec3 L = ray.getDirection();
	glm::vec3 N;
	if (leaf->closest == "TRIANGLE") N = leaf->triangle.getNormal();
	else if (leaf->closest == "SPHERE") N = glm::normalize(leaf->point - leaf->sphere.getCenter());
	glm::vec3 R = glm::normalize(L - 2.0f*glm::dot(N, L)*N)*100.0f;

	return Ray(leaf->point + N * 0.001f, R);
}

Ray Scene::getRefraction(Ray ray, Intersection* leaf) const {
	//T=(n1/n2)*L + N*(-(n1/n2)*dot(N,L)-sqrt(1-(n1/n2)^2*(1-dot(N,L)^2)))
	glm::vec3 L = ray.getDirection();
	glm::vec3 N;
	glm::vec3 T;
	float n;

	if (leaf->closest == "TRIANGLE") {
		n = leaf->triangle.getMaterial().getN();
		N = leaf->triangle.getNormal();
		T = glm::normalize((1.0f / n)*L + N * (-(1.0f / n)*glm::dot(N, L) - sqrt(1.0f - pow(1.0f / n, 2.0f)*(1 - pow(glm::dot(N, L), 2.0f)))))*100.0f;
	}
	else if (leaf->closest == "SPHERE") {
		n = leaf->sphere.getMaterial().getN();
		N = glm::normalize(leaf->point - leaf->sphere.getCenter());
		T = glm::normalize((1.0f / n)*L + N * (-(1.0f / n)*glm::dot(N, L) - sqrt(1.0f - pow(1.0f / n, 2.0f)*(1 - pow(glm::dot(N, L), 2.0f)))))*100.0f;
	}

	return Ray(leaf->point - N * 0.001f, T);
}




bool Scene::isVisible(Ray ray) const {
	glm::vec3 intersection;
	float distance = ray.getLength();
	for (Triangle triangle : triangles) {
		if (triangle.rayIntersection(ray, intersection)) {
			if (glm::length(intersection) < distance && intersection.z < 4.0f)
				return false;
		}
	}
	for (Sphere sphere : spheres) {
		if (sphere.rayIntersection(ray, intersection)) {
			//if (glm::length(intersection) < distance)
			return false;
			//Something is wrong with sphere distance
				
		}
	}

	return true;
}



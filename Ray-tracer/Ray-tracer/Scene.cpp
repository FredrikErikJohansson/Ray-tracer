#include "Scene.h"


Scene::Scene()
{
	//Create the tetrahedron
	tetrahedron.createTetrahedron();
}




Scene::~Scene()
{
}

float Scene::uniformRand() {
	return DISTR(GENERATOR);
}

float Scene::randMinMax(const float &min, const float &max) {
	return min + uniformRand() * (max - min);
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
	triangles[6].setColor(glm::vec3(1.0f));
	triangles[7].setColor(glm::vec3(1.0f));
	triangles[8].setColor(glm::vec3(0.87f, 0, 0));
	triangles[9].setColor(glm::vec3(0.87f, 0, 0));
	triangles[10].setColor(glm::vec3(1.0f));
	triangles[11].setColor(glm::vec3(1.0f));

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
	triangles[12].setColor(glm::vec3(1.0f));
	triangles[13].setColor(glm::vec3(1.0f));
	triangles[14].setColor(glm::vec3(0, 0.87f, 0));
	triangles[15].setColor(glm::vec3(0, 0.87f, 0));
	triangles[16].setColor(glm::vec3(1.0f));
	triangles[17].setColor(glm::vec3(1.0f));

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

	//Light vertices
	triangles[24].setVertices(glm::vec4(4, 1, 4.99f, 1), glm::vec4(6, 1, 4.99f, 1), glm::vec4(6, -1, 4.99f, 1));
	triangles[25].setVertices(glm::vec4(6, -1, 4.99f, 1), glm::vec4(4, -1, 4.99f, 1), glm::vec4(4, 1, 4.99f, 1));
	//Light normals
	triangles[24].setNormal(glm::vec3(0, 0, -1));
	triangles[25].setNormal(glm::vec3(0, 0, -1));
	//Light color
	triangles[24].setColor(glm::vec3(1, 1, 1));
	triangles[25].setColor(glm::vec3(1, 1, 1));


	//Get the triangles of the tetrahedron
	for (int i = 0; i < tetrahedronTriangleAmount; i++) {
		triangles[sceneTriangles + i] = tetrahedron.getTetrahedronTriangles(i);
	}

	Material pureTransp;
	pureTransp.setType("TRANSPARENT");
	pureTransp.setN(1.5f);
	pureTransp.setReflectCof(0.2f);

	Material pureReflect;
	pureReflect.setType("MIRROR");

	Material lambertian;
	lambertian.setType("LAMBERTIAN");
	lambertian.setReflectCof(0.5f);

	Material light;
	light.setType("LIGHT");

	//Light mat
	triangles[24].setMaterial(light);
	triangles[25].setMaterial(light);

	//Tetra mat
	triangles[26].setMaterial(lambertian);
	triangles[27].setMaterial(lambertian);
	triangles[28].setMaterial(lambertian);
	triangles[29].setMaterial(lambertian);

	//Spheres
	spheres[0].setCenter(glm::vec3(5, 3, 1));
	spheres[0].setRadius(1.0f);
	spheres[0].setColor(glm::vec3(1, 1, 1));
	spheres[0].setMaterial(lambertian);

	spheres[1].setCenter(glm::vec3(8, 4, -4.0f));
	spheres[1].setRadius(1.0f);
	spheres[1].setColor(glm::vec3(1, 1, 1));
	spheres[1].setMaterial(pureReflect);

	spheres[2].setCenter(glm::vec3(6, -3.5f, -1.0f));
	spheres[2].setRadius(1.0f);
	spheres[2].setColor(glm::vec3(0, 0, 0));
	spheres[2].setMaterial(pureTransp);

	//DEBUGGING MAT
	for (int i = 0; i <= 23; i++)
	{
		triangles[i].setMaterial(lambertian);
	}
	//DEBUGGING MAT
	/*for (int i = 14; i <= 15; i++)
	{
		triangles[i].setMaterial(pureReflect);
	}*/
}

glm::vec3 Scene::getIntersection(Ray ray, Intersection* root, bool &inside) {

	float reflectCof, refTheta = 1.0f;
	float minDistance = 1000.0f;

	glm::vec3 color = glm::vec3(0.0f);
	glm::vec3 reflectedLight = glm::vec3(0.f);
	glm::vec3 refractedLight = glm::vec3(0.f);
	glm::vec3 intersection = glm::vec3(0.0f);
	glm::vec3 indirectLight = glm::vec3(0.0f);
	glm::vec3 directLight = glm::vec3(0.0f);

	Ray nextRay;
	
	for (Triangle triangle : triangles) {
		if (triangle.rayIntersection(ray, intersection, inside)) {
			if (glm::length(intersection - glm::vec3(ray.getStartPoint())) < minDistance) {
				minDistance = glm::length(intersection - glm::vec3(ray.getStartPoint()));
				root->triangle = triangle;
				root->point = intersection + 0.001f * triangle.getNormal();
				root->closest = "TRIANGLE";
			}
		}
	}
	for (Sphere sphere : spheres) {
		if (sphere.rayIntersection(ray, intersection, inside)) {
			if (glm::length(intersection - glm::vec3(ray.getStartPoint())) < minDistance) {
				minDistance = glm::length(intersection - glm::vec3(ray.getStartPoint()));
				root->sphere = sphere;
				root->point = intersection + 0.001f * root->sphere.getNormal(intersection);
				root->closest = "SPHERE";
			}
		}
	}

	if (root->closest == "") return glm::vec3(0.0f);

	if (ray.getdepth() < 20) {
		if (root->closest == "TRIANGLE") {
			if (root->triangle.getMaterial().getType() == "LIGHT") {
				return lightBrightness;
			}
			else if (root->triangle.getMaterial().getType() == "MIRROR") {

				root->R = new Intersection();
				ray++;
				nextRay = this->getReflection(ray, root, inside);
				nextRay.setDepth(ray.getdepth());
				reflectCof = root->triangle.getMaterial().getReflectCof();
				reflectedLight = this->getIntersection(nextRay, root->R, inside) * reflectCof;
			}
			else if (root->triangle.getMaterial().getType() == "TRANSPARENT") {

				//Schlicks law
				reflectCof = pow(((1.0f - root->triangle.getMaterial().getN()) / (1.0f + root->triangle.getMaterial().getN())), 2.0f);
				refTheta = reflectCof + (1 - reflectCof) * pow((1.0f - cos(glm::dot(ray.getDirection(), root->triangle.getNormal()))), 5.0f);

				root->R = new Intersection();
				ray++;
				nextRay = this->getReflection(ray, root, inside);
				nextRay.setDepth(ray.getdepth());
				reflectedLight = this->getIntersection(nextRay, root->R, inside);

				nextRay = this->getRefraction(ray, root, inside);
				if (reflectedLight != lightBrightness && glm::vec3(nextRay.getStartPoint()) != glm::vec3(0.0f) && glm::vec3(nextRay.getEndPoint()) != glm::vec3(0.0f)) {
					reflectedLight *= refTheta;
					root->T = new Intersection();
					ray++;
					nextRay.setDepth(ray.getdepth());
					refractedLight = this->getIntersection(nextRay, root->T, inside) * (1.0f - refTheta);
				}
	
			}
			else if (root->triangle.getMaterial().getType() == "LAMBERTIAN") {
				
				nextRay = this->getRandomRay(ray, root);

				if (glm::vec3(nextRay.getStartPoint()) != glm::vec3(0.0f) && glm::vec3(nextRay.getEndPoint()) != glm::vec3(0.0f)) {
					root->R = new Intersection();
					ray++;
					nextRay.setDepth(ray.getdepth());
					reflectCof = root->triangle.getMaterial().getReflectCof();
					reflectedLight = reflectCof * (this->getIntersection(nextRay, root->R, inside));
				}
			}
		}
		else if (root->closest == "SPHERE") {
			if (root->sphere.getMaterial().getType() == "MIRROR") {

				root->R = new Intersection();
				ray++;
				nextRay = this->getReflection(ray, root, inside);
				nextRay.setDepth(ray.getdepth());
				reflectCof = root->sphere.getMaterial().getReflectCof();
				reflectedLight = this->getIntersection(nextRay, root->R, inside) * reflectCof;
			}
			else if (root->sphere.getMaterial().getType() == "TRANSPARENT") {

				//Schlicks law
				reflectCof = pow(((1.0f - root->sphere.getMaterial().getN()) / (1.0f + root->sphere.getMaterial().getN())), 2.0f);
				refTheta = reflectCof + (1 - reflectCof) * pow((1.0f - cos(glm::dot(ray.getDirection(), root->sphere.getNormal(root->point)))), 5.0f);

				root->R = new Intersection();
				ray++;
				nextRay = this->getReflection(ray, root, inside);
				nextRay.setDepth(ray.getdepth());
				reflectedLight = this->getIntersection(nextRay, root->R, inside);
						
				nextRay = this->getRefraction(ray, root, inside);
				if(reflectedLight != lightBrightness && glm::vec3(nextRay.getStartPoint()) != glm::vec3(0.0f) && glm::vec3(nextRay.getEndPoint()) != glm::vec3(0.0f)) {
					reflectedLight *= refTheta;	
					root->T = new Intersection();
					ray++;
					nextRay.setDepth(ray.getdepth());
					refractedLight = this->getIntersection(nextRay, root->T, inside) * (1.0f - refTheta);
				}
			
			}
			else if (root->sphere.getMaterial().getType() == "LAMBERTIAN") {

				nextRay = this->getRandomRay(ray, root);

				if (glm::vec3(nextRay.getStartPoint()) != glm::vec3(0.0f) && glm::vec3(nextRay.getEndPoint()) != glm::vec3(0.0f)) {
					root->R = new Intersection();
					ray++;
					nextRay.setDepth(ray.getdepth());
					reflectCof = root->sphere.getMaterial().getReflectCof();
					reflectedLight = reflectCof * (this->getIntersection(nextRay, root->R, inside));
				}
			}
		}
	}
	ray--;


	indirectLight = reflectedLight + refractedLight;
	if (root->closest == "TRIANGLE") {
		if (root->triangle.getMaterial().getType() != "MIRROR" && root->triangle.getMaterial().getType() != "TRANSPARENT")
			directLight = calculateDirectLight(root);
	}
	else if (root->closest == "SPHERE") {
		if (root->sphere.getMaterial().getType() != "MIRROR" && root->sphere.getMaterial().getType() != "TRANSPARENT")
			directLight = calculateDirectLight(root);
	}

	return (indirectLight + directLight);
};

glm::vec3 Scene::calculateDirectLight(Intersection* root) {

	glm::vec3 Ld, L = glm::vec3(0.0);
	int const numberOfShadowRays = 30;
	float pi = 3.1415926535897f;

	glm::vec3 v0 = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 v1 = glm::vec3(0.0f, 2.0f, 0.0f);
	glm::vec3 v2 = glm::vec3(2.0f, 0.0f, 0.0f);
	glm::vec3 v3 = glm::vec3(2.0f, 2.0f, 0.0f);	

	glm::vec3 LightSourceNormal = glm::vec3(0, 0, -1);

	float A = glm::length(glm::cross(v1 - v0, v3 - v0));
	glm::vec3 q = glm::vec3(0.0f);
	glm::vec3 Sk = glm::vec3(0.0f);

	float cosAlpha, cosBeta, u, v, d, Vk = 0.0f;

	//Direct light
	//Check if the intersection is visible with multiple shadowrays
	for (int i = 0; i < numberOfShadowRays; i++) {
		
		u = uniformRand();
		v = uniformRand();

		q = u * (v1 - v0) + v * (v2 - v0);

		//Magic
		q.x += 4.0f;
		q.y -= 1.0f;
		q.z += 4.99f;
		
		Sk = q - root->point;
		d = glm::length(Sk);
		Ray shadowRay = Ray(root->point, q);

		cosAlpha = glm::dot(-Sk, LightSourceNormal);
 
		if (!this->isVisible(shadowRay)) Vk = 0.0f;
		else Vk = 1.0f;

		if (root->point.z > 4.99f) Vk = 0.0f;

		//TODO: Take into account BRDF on L (For now only lambertian)
		if (root->closest == "TRIANGLE") {
			cosBeta = glm::dot(Sk, root->triangle.getNormal());
			L += root->triangle.getColor()*(((cosAlpha*cosBeta) / (d*d))*Vk);
		}
			
		else if (root->closest == "SPHERE") {
			cosBeta = glm::dot(Sk, root->sphere.getNormal(root->point));
			L += root->sphere.getColor()*(((cosAlpha*cosBeta) / (d*d))*Vk);
		}	
	}
	
	Ld = ((A*1.0f) / numberOfShadowRays)*L;
	return Ld;
}

Ray Scene::getRandomRay(Ray ray, Intersection* root) {
	float pi = 3.1415926535897f;
	float rand1, rand2 = 0.0f;
	float terminate = 0.25f;

	glm::vec3 helper = glm::vec3(0.0f);
	glm::vec3 tangent = glm::vec3(0.0f);
	glm::vec3 random_direction = glm::vec3(0.0f);
	glm::vec3 N = glm::vec3(0.0f);

	rand1 = uniformRand();
	rand2 = uniformRand();

	if (root->closest == "TRIANGLE") {
		N = root->triangle.getNormal();
		helper = N + glm::vec3(1, 1, 1);
		tangent = glm::normalize(glm::cross(N, helper));
		random_direction = N;
	}
	else if (root->closest == "SPHERE") {
		N = root->sphere.getNormal(root->point);
		helper = N + glm::vec3(1, 1, 1);
		tangent = glm::normalize(glm::cross(N, helper));
		random_direction = N;
	}

	float inclination = asin(sqrt(rand1));
	float azimuth = 0.0f;
	if(rand2 <= (1.0f - terminate))
		azimuth = 2.0f * pi / (rand2);
	else return  Ray(glm::vec3(0.0f), glm::vec3(0.0f));

	
	random_direction = glm::normalize(glm::rotate(
		random_direction,
		inclination,
		tangent));
	random_direction = glm::normalize(glm::rotate(
		random_direction,
		azimuth,
		N));

	return Ray(root->point + N * 0.001f, random_direction*100.0f);
}


Ray Scene::getReflection(Ray ray, Intersection* leaf, bool &inside) {
	glm::vec3 L = ray.getDirection();
	glm::vec3 N = glm::vec3(0.0f);
	if (leaf->closest == "TRIANGLE") {
		N = leaf->triangle.getNormal();
		if (leaf->triangle.getMaterial().getType() == "TRANSPARENT") inside = true;
		else inside = false;
	}
	else if (leaf->closest == "SPHERE") {
		N = glm::normalize(leaf->point - leaf->sphere.getCenter());
		if (leaf->triangle.getMaterial().getType() == "TRANSPARENT") inside = true;
		else inside = false;
	}

	if (inside) N = -N;

	glm::vec3 R = glm::normalize(L - 2.0f*glm::dot(N, L)*N)*100.0f;

	return Ray(leaf->point + N * 0.002f, R);
}

Ray Scene::getRefraction(Ray ray, Intersection* leaf, bool &inside) {
	glm::vec3 L = ray.getDirection();
	glm::vec3 N, T = glm::vec3(0.0f);
	float n, nVar, brewster, alpha = 0;
	
	if (leaf->closest == "TRIANGLE") {
		n = leaf->triangle.getMaterial().getN();

		if (inside) {
			N = -leaf->triangle.getNormal();
			nVar = (n / 1.0f);
			brewster = asin(1.0f / n);
			alpha = acos(glm::dot(L, N));
			if (brewster >= alpha) {
				inside = false;
				return Ray(glm::vec3(0.0f), glm::vec3(0.0f));
			}
		}
		else {
			N = leaf->triangle.getNormal();
			nVar = (1.0f / n);
			inside = true;
		}
		
		T = glm::normalize(nVar *L + N * (-nVar *glm::dot(N, L) - sqrt(1.0f - pow(nVar, 2.0f)*(1 - pow(glm::dot(N, L), 2.0f)))))*100.0f;
	}
	else if (leaf->closest == "SPHERE") {
		n = leaf->sphere.getMaterial().getN();	

		if (inside) {
			N = -leaf->sphere.getNormal(leaf->point);
			nVar = (n / 1.0f);
			brewster = asin(1.0f / n);
			alpha = acos(glm::dot(L, N));	
			if (brewster >= alpha) {
				inside = false;
				return Ray(glm::vec3(0.0f), glm::vec3(0.0f));
			}

		}
		else {
			N = leaf->sphere.getNormal(leaf->point);
			nVar = (1.0f / n);
			inside = true;
		}

		T = glm::normalize(nVar *L + N * (-nVar *glm::dot(N, L) - sqrt(1.0f - pow(nVar, 2.0f)*(1 - pow(glm::dot(N, L), 2.0f)))))*100.0f;
	}

	return Ray(leaf->point - N * 0.002f, T);
}


bool Scene::isVisible(Ray ray) const {
	float distance = ray.getLength();

	glm::vec3 intersection = glm::vec3(0.0f);
	float minDistance = 1000.0f;
	for (Triangle triangle : triangles) {
		if (triangle.rayIntersection(ray, intersection, false)) {
			if (glm::length(intersection - glm::vec3(ray.getStartPoint())) < minDistance) {
				minDistance = glm::length(intersection - glm::vec3(ray.getStartPoint()));
			}
		}
	}
	for (Sphere sphere : spheres) {
		if (sphere.rayIntersection(ray, intersection, false)) {
			if (glm::length(intersection - glm::vec3(ray.getStartPoint())) < minDistance) {
				minDistance = glm::length(intersection - glm::vec3(ray.getStartPoint()));
			}
		}
	}

	if (minDistance < distance) return false;

	return true;
}



#include "Scene.h"


Scene::Scene()
{
}

void Scene::createScene() {
	//Floor vertices
	triangles[0].setVertices(Vertex(-3, 0, -5, 1), Vertex(5, 0, -5, 1), Vertex(0, -6, -5, 1));
	triangles[1].setVertices(Vertex(0, -6, -5, 1), Vertex(5, 0, -5, 1), Vertex(10, -6, -5, 1));
	triangles[2].setVertices(Vertex(10, -6, -5, 1), Vertex(5, 0, -5, 1), Vertex(13, 0, -5, 1));
	triangles[3].setVertices(Vertex(13, 0, -5, 1), Vertex(5, 0, -5, 1), Vertex(10, 6, -5, 1));
	triangles[4].setVertices(Vertex(10, 6, -5, 1), Vertex(5, 0, -5, 1), Vertex(0, 6, -5, 1));
	triangles[5].setVertices(Vertex(0, 6, -5, 1), Vertex(5, 0, -5, 1), Vertex(-3, 0, -5, 1));

	//Floor colors
	triangles[0].setColor(ColorDbl(1, 1, 1));
	triangles[1].setColor(ColorDbl(1, 1, 1));
	triangles[2].setColor(ColorDbl(1, 1, 1));
	triangles[3].setColor(ColorDbl(1, 1, 1));
	triangles[4].setColor(ColorDbl(1, 1, 1));
	triangles[5].setColor(ColorDbl(1, 1, 1));

	//Floor normals
	triangles[0].setNormal(Direction(0, 0, 1));
	triangles[1].setNormal(Direction(0, 0, 1));
	triangles[2].setNormal(Direction(0, 0, 1));
	triangles[3].setNormal(Direction(0, 0, 1));
	triangles[4].setNormal(Direction(0, 0, 1));
	triangles[5].setNormal(Direction(0, 0, 1));

	//Walls vertices (left)
	triangles[6].setVertices(Vertex(-3, 0, -5, 1), Vertex(-3, 0, 5, 1), Vertex(0, 6, -5, 1));
	triangles[7].setVertices(Vertex(0, 6, -5, 1), Vertex(-3, 0, 5, 1), Vertex(0, 6, 5, 1));
	triangles[8].setVertices(Vertex(0, 6, -5, 1), Vertex(0, 6, 5, 1), Vertex(10, 6, -5, 1));
	triangles[9].setVertices(Vertex(10, 6, -5, 1), Vertex(0, 6, 5, 1), Vertex(10, 6, 5, 1));
	triangles[10].setVertices(Vertex(10, 6, -5, 1), Vertex(10, 6, 5, 1), Vertex(13, 0, -5, 1));
	triangles[11].setVertices(Vertex(13, 0, -5, 1), Vertex(10, 6, 5, 1), Vertex(13, 0, 5, 1));

	//Walls colors (left)
	triangles[6].setColor(ColorDbl(1, 0, 0));
	triangles[7].setColor(ColorDbl(1, 0, 0));
	triangles[8].setColor(ColorDbl(0, 1, 0));
	triangles[9].setColor(ColorDbl(0, 1, 0));
	triangles[10].setColor(ColorDbl(0, 0, 1));
	triangles[11].setColor(ColorDbl(0, 0, 1));

	//Walls normals (left)
	triangles[6].setNormal(Direction(2 / sqrt(5), -1 / sqrt(5), 0));
	triangles[7].setNormal(Direction(2 / sqrt(5), -1 / sqrt(5), 0));
	triangles[8].setNormal(Direction(0, -1, 0));
	triangles[9].setNormal(Direction(0, -1, 0));
	triangles[10].setNormal(Direction(-2 / sqrt(5), -1 / sqrt(5), 0));
	triangles[11].setNormal(Direction(-2 / sqrt(5), -1 / sqrt(5), 0));

	//Walls vertices (right)
	triangles[12].setVertices(Vertex(13, 0, -5, 1), Vertex(13, 0, 5, 1), Vertex(10, -6, -5, 1));
	triangles[13].setVertices(Vertex(10, -6, -5, 1), Vertex(13, 0, 5, 1), Vertex(10, -6, 5, 1));
	triangles[14].setVertices(Vertex(10, -6, -5, 1), Vertex(10, -6, 5, 1), Vertex(0, -6, -5, 1));
	triangles[15].setVertices(Vertex(0, -6, -5, 1), Vertex(10, -6, 5, 1), Vertex(0, -6, 5, 1));
	triangles[16].setVertices(Vertex(0, -6, -5, 1), Vertex(0, -6, 5, 1), Vertex(-3, 0, -5, 1));
	triangles[17].setVertices(Vertex(-3, 0, -5, 1), Vertex(0, -6, 5, 1), Vertex(-3, 0, 5, 1));

	//Walls colors (right)
	triangles[6].setColor(ColorDbl(0.5, 0.5, 0));
	triangles[7].setColor(ColorDbl(0.5, 0.5, 0));
	triangles[8].setColor(ColorDbl(0, 0.5, 0.5));
	triangles[9].setColor(ColorDbl(0, 0.5, 0.5));
	triangles[10].setColor(ColorDbl(0.5, 0, 0.5));
	triangles[11].setColor(ColorDbl(0.5, 0, 0.5));

	//Walls normals (right)
	triangles[12].setNormal(Direction(-2 / sqrt(5), 1 / sqrt(5), 0));
	triangles[13].setNormal(Direction(-2 / sqrt(5), 1 / sqrt(5), 0));
	triangles[14].setNormal(Direction(0, 1, 0));
	triangles[15].setNormal(Direction(0, 1, 0));
	triangles[16].setNormal(Direction(2 / sqrt(5), 1 / sqrt(5), 0));
	triangles[17].setNormal(Direction(2 / sqrt(5), 1 / sqrt(5), 0));

	//Roof vertices
	triangles[18].setVertices(Vertex(-3, 0, 5, 1), Vertex(5, 0, 5, 1), Vertex(0, -6, 5, 1));
	triangles[19].setVertices(Vertex(0, -6, 5, 1), Vertex(5, 0, 5, 1), Vertex(10, -6, 5, 1));
	triangles[20].setVertices(Vertex(10, -6, 5, 1), Vertex(5, 0, 5, 1), Vertex(13, 0, 5, 1));
	triangles[21].setVertices(Vertex(13, 0, 5, 1), Vertex(5, 0, 5, 1), Vertex(10, 6, 5, 1));
	triangles[22].setVertices(Vertex(10, 6, 5, 1), Vertex(5, 0, 5, 1), Vertex(0, 6, 5, 1));
	triangles[23].setVertices(Vertex(0, 6, 5, 1), Vertex(5, 0, 5, 1), Vertex(-3, 0, 5, 1));

	//Roof colors
	triangles[18].setColor(ColorDbl(1, 1, 1));
	triangles[19].setColor(ColorDbl(1, 1, 1));
	triangles[20].setColor(ColorDbl(1, 1, 1));
	triangles[21].setColor(ColorDbl(1, 1, 1));
	triangles[22].setColor(ColorDbl(1, 1, 1));
	triangles[23].setColor(ColorDbl(1, 1, 1));

	//Roof normals
	triangles[18].setNormal(Direction(0, 0, -1));
	triangles[19].setNormal(Direction(0, 0, -1));
	triangles[20].setNormal(Direction(0, 0, -1));
	triangles[21].setNormal(Direction(0, 0, -1));
	triangles[22].setNormal(Direction(0, 0, -1));
	triangles[23].setNormal(Direction(0, 0, -1));
}


Scene::~Scene()
{
}

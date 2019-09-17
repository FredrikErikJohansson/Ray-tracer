#pragma once

#include "Triangle.h"

class Scene
{
public:
	Scene();
	~Scene();

	void createScene() {
		//Floor
		triangle01.setVertices(Vertex(-3, 0, -5, 1), Vertex(5, 0, -5, 1), Vertex(0, -6, -5, 1));
		triangle02.setVertices(Vertex(0, -6, -5, 1), Vertex(5, 0, -5, 1), Vertex(10, -6, -5, 1));
		triangle03.setVertices(Vertex(10, -6, -5, 1), Vertex(5, 0, -5, 1), Vertex(13, 0, -5, 1));
		triangle04.setVertices(Vertex(13, 0, -5, 1), Vertex(5, 0, -5, 1), Vertex(10, 6, -5, 1));
		triangle05.setVertices(Vertex(10, 6, -5, 1), Vertex(5, 0, -5, 1), Vertex(0, 6, -5, 1));
		triangle06.setVertices(Vertex(0, 6, -5, 1), Vertex(5, 0, -5, 1), Vertex(-3, 0, -5, 1));

		triangle01.setNormal(Direction(0, 0, 1));
		triangle02.setNormal(Direction(0, 0, 1));
		triangle03.setNormal(Direction(0, 0, 1));
		triangle04.setNormal(Direction(0, 0, 1));
		triangle05.setNormal(Direction(0, 0, 1));
		triangle06.setNormal(Direction(0, 0, 1));

		//Walls

		//Roof
	}

private:
	Triangle triangle01, triangle02, triangle03, triangle04, triangle05, triangle06;
	Triangle triangle07, triangle08, triangle09, triangle10, triangle11, triangle12;
	Triangle triangle13, triangle14, triangle15, triangle16, triangle17, triangle18;
	Triangle triangle19, triangle20, triangle21, triangle22, triangle23, triangle24;
};


#pragma once
class Vertex
{
public:
	Vertex();

	Vertex(int _x, int _y, int _z, int _w) {
		x = _x;
		y = _y;
		z = _z;
		w = _w;
	}

	~Vertex();

private:
	int x;
	int y;
	int z;
	int w;
};


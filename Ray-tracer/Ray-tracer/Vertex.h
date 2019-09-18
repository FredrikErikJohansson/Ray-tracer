#pragma once
class Vertex
{
public:
	Vertex();

	Vertex(double _x, double _y, double _z, double _w) {
		x = _x;
		y = _y;
		z = _z;
		w = _w;
	}

	~Vertex();

private:
	double x;
	double y;
	double z;
	double w;
};


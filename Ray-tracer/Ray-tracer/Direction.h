#pragma once

class Direction
{
public:
	Direction();

	Direction(double _x, double _y, double _z) {
		x = _x;
		y = _y;
		z = _z;
	}

	~Direction();

private:
	double x;
	double y;
	double z;
};


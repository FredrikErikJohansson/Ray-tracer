#pragma once

#include "ColorDbl.h"
#include "Ray.h"

class Pixel
{
public:
	Pixel();
	~Pixel();

	ColorDbl getColor(){
		return color;
	}

	void setColor(double _red, double _green, double _blue) {
		color = ColorDbl(_red, _green, _blue);
	}

private:
	ColorDbl color;
	Ray ray;
};


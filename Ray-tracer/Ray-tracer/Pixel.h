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

private:
	ColorDbl color;
	Ray ray;
};


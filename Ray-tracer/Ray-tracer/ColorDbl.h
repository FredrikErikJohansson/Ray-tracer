#pragma once
class ColorDbl
{
public:
	ColorDbl();

	ColorDbl(double _red, double _green, double _blue) {
		red = _red;
		green = _green;
		blue = _blue;
	}

	~ColorDbl();

	double getRed() {
		return red;
	}

	double getGreen() {
		return green;
	}

	double getBlue() {
		return blue;
	}

private:
	double red;
	double green;
	double blue;
};


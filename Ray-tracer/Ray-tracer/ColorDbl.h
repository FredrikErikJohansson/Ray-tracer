#pragma once
class ColorDbl
{
public:
	ColorDbl();
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


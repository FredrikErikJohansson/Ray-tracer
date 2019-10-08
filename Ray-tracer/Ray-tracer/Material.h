#pragma once

#include <string>

class Material
{
public:
	Material();
	~Material();

	void setType(std::string _mType);
	void setN(float _n);

	std::string getType() const;
	float getN() const;

private:
	std::string mType = "DIFFUSE";
	float n = 1.0f;
};


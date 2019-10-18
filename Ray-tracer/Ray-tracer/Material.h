#pragma once

#include <string>

class Material
{
public:
	Material();
	~Material();

	void setType(std::string _mType);
	void setN(float _n);
	void setReflectCof(float _i);

	std::string getType() const;
	float getN() const;
	float getReflectCof() const;

private:
	std::string mType = "DIFFUSE";
	float reflectCof = 1.0f;
	float n = 1.0f;
};


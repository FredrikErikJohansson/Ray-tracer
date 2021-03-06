#pragma once

#include <string>

//TODO: Change to BRDF
//Lambertian as standard
//Pure reflective
//Transparent - for grade 4
//Oren-nayar - for grade 4
//Maybe add lightsource as a BRDF

class Material
{
public:
	Material();
	~Material();

	void setType(std::string _mType);
	void setN(float _n);
	void setReflectCof(float _i);
	void setRoughness(float _r);

	std::string getType() const;
	float getN() const;
	float getReflectCof() const;
	float getRoughness() const;

private:
	std::string mType = "DIFFUSE";
	float reflectCof = 1.0f;
	float n = 1.0f;
	float roughness = 1.0f;
};


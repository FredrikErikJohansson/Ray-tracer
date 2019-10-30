#include "Material.h"



Material::Material()
{
}


Material::~Material()
{
}

void Material::setType(std::string _mType) {
	mType = _mType;
}

void Material::setN(float _n) {
	n = _n;
}

void Material::setReflectCof(float _i) {
	reflectCof = _i;
}

void Material::setRoughness(float _r) {
	roughness = _r;
}

std::string Material::getType() const {
	return mType;
}

float Material::getN() const {
	return n;
}

float Material::getReflectCof() const {
	return reflectCof;
}

float Material::getRoughness() const {
	return roughness;
}

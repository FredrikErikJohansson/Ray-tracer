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

std::string Material::getType() const {
	return mType;
}

float Material::getN() const {
	return n;
}

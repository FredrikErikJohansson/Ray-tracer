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

void Material::setN(int _n) {
	n = _n;
}

std::string Material::getType() const {
	return mType;
}

int Material::getN() const {
	return n;
}

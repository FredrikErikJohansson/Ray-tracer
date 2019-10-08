#pragma once

#include <string>

class Material
{
public:
	Material();
	~Material();

	void setType(std::string _mType);
	void setN(int _n);

	std::string getType() const;
	int getN() const;

private:
	std::string mType = "DIFFUSE";
	int n = 1;
};


#include "Intersection.h"


Intersection::~Intersection()
{
}

void Intersection::destroy() {
	if (this) {
		this->R->destroy();
		this->T->destroy();
		delete this;
	}
}

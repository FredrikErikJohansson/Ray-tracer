#include "IntersectionTree.h"



IntersectionTree::IntersectionTree()
{
	root = nullptr;
}


IntersectionTree::~IntersectionTree()
{
	destroy_tree(root);
}


void IntersectionTree::destroy_tree(Intersection *leaf) {
	if (leaf != NULL) {
		destroy_tree(leaf->R);
		destroy_tree(leaf->T);
		delete leaf;
	}
}


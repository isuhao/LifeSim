#include "BoundingBox.h"
#include <list>

BoundingBox::BoundingBox()
{
	layer = 0;
	parent = NULL;
}

BoundingBox::BoundingBox(int l, BoundingBox *p)
{
	layer = l;
	parent = p;
}


BoundingBox::~BoundingBox()
{
}

BoundingBox* BoundingBox::getParent() {
	return parent;
}

std::list<BoundingBox> BoundingBox::getChildren() {
	return children;
}

int BoundingBox::getLayer() {
	return layer;
}

uint BoundingBox::numChildren() {
	return uint(children.size());
}

bool BoundingBox::addChild(BoundingBox b) {
	if ((b.getLayer() <= layer + 1) && b.getLayer() >= layer - 1) {
		children.push_back(b);
		return true;
	}
	else
		return false;
}

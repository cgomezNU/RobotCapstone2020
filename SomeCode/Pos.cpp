#include "Pos.h"

Pos& Pos::operator=(Pos other) {
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;

	return *this;
}

Pos::Pos(const Pos& p)
{
	x = p.x;
	y = p.y;
	z = p.z;
}

Pos::Pos(double x_, double y_, double z_) {
	x = x_;
	y = y_;
	z = z_;
}

double Pos::magnitude()
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}
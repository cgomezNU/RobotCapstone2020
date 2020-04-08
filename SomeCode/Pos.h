#include <cmath>
#pragma once
class Pos {
private:
	double x, y, z;

public:
	Pos() { x = 0; y = 0; x = 0; }
	Pos(const Pos& p);
	Pos(double x_, double y_, double z_);
	Pos& operator=(Pos other) {
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;

		return *this;
	}

	friend Pos operator-(Pos& p1, Pos& p2) {
		Pos n;

		n.x = p1->x - p2.x;
		n.y = p1->y - p2.y;
		n.z = p1->z - p2.z;

		return n;
	}

	friend Pos operator+(Pos& p1, Pos& p2) {
		Pos n;

		n.x = p1->x + p2.x;
		n.y = p1->y + p2.y;
		n.z = p1->z + p2.z;

		return n;
	}

	friend Pos operator*(double d, Pos& p) {
		Pos n;

		n.x = d * p.x;
		n.y = d * p.y;
		n.z = d * p.z;

		return n;
	}


	friend bool operator>(Pos& p1, Pos& p2) {

		return p1->x > p2.x || p1->y > p2.y || p1->z > p2.z;
	}

	double magnitude();
};

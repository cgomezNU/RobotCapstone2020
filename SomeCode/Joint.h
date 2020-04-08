#pragma once
#include "AnlogSens.h"
#include "PID.h"
#include <cmath>
#include "Pos.h"

class Joint
{
	private:
		static const int JOINTS = 4;
		// joint end position
		Pos jointP[JOINTS];
		// distances between joints
		double jointDis[JOINTS];
		// Sensor
		AnlogSens sens;
		int relay;
		// PID controller for arm
		PID contr;
		// Max extension that can be achieved by arm
		Pos maxExt;
		// tolerance
		double tol;

	public:
		Joint(Pos maxExtension, AnlogSens sensor);
		~Joint();
		void moveArm(Pos target);

};


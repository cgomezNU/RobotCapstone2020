#include "Joint.h"

Joint::Joint(Pos maxExtension, AnlogSens sensor)
{
}


Joint::~Joint()
{
}

// calculates new joint positions based on the FABRIK algorithm expored on http://www.andreasaristidou.com/publications/papers/FABRIK.pdf
void Joint::moveArm(Pos target)
{
	// distance between root and target
	Pos temp = jointP[0] - target;
	double dist = temp.magnitude();

	//check if distance to the target is greater than achivable
	// if distance to target is greater than the maximum reach of arm
	if (target > maxExt) {
		printf("Target is unreachable");
		for (int i = 0; i < JOINTS; i++) {
			// find distance between target and joint
			Pos temp = jointP[i] - target;
			double r = temp.magnitude();
			double lambd = jointDis[i] / r;
			// Find the new joint positions
			Pos temp = (1 - lambd)*jointP[i];
			Pos temp1 = lambd * target;
			jointP[i] = temp + temp1;
		}
	}
	// if distance to target is less than the maximum reach of arm
	else{
		// set b as initial position
		Pos b = jointP[0];
		// Check whether the distance between the end effector and the target is greater than a tolerance
		Pos temp = jointP[JOINTS] - target;
		double diff_A = temp.magnitude();
		// Check whether the distance between the end effector and the target 
		while (diff_A > tol) {
			// Stage 1: FORWARD REACHING
			// set end effector as a target
			jointP[JOINTS] = target;
			for (int i = JOINTS - 1; i >= 0; i--) {
				// find distance r between the new joint position and the former joint
				Pos temp = jointP[i + 1] - jointP[i];
				double r = temp.magnitude();
				double lambd = jointDis[i] / r;
				// find new joint positions 
				Pos temp = (1 - lambd) * jointP[i + 1];
				Pos temp1 = lambd * jointP[i];
				jointP[i] = temp - temp1;
			}

			// Stage 2: BACKWARD REACHING
			// set root to its initial position
			jointP[0] = b;
			for (int i = 1; i < JOINTS; i++) {
				// find distance r between the new joint position and the former joint
				Pos temp = jointP[i + 1] - jointP[i];
				double r = temp.magnitude();
				double lambd = jointDis[i] / r;
				// find new joint positions 
				Pos temp = (1 - lambd) * jointP[i];
				Pos temp1 = lambd * jointP[i+1];
				jointP[i] = temp - temp1;
			}
			Pos temp = jointP[JOINTS] - target;
			diff_A = temp.magnitude();
		}
	}
}

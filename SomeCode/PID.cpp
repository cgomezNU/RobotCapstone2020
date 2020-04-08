#include "PID.h"

PID::PID()
{
}

PID::PID(double dt, double max, double min, double Kp, double Kd, double Ki)
{
}

PID::~PID()
{
}

double PID::calculate(double setpoint, double x)
{

	// Calculate error
	double error = setpoint - x;

	// Proportional term
	double Pout = Kp * error;

	// Integral term
	integral += error * dt;
	double Iout = Ki * integral;

	// Derivative term
	double derivative = (error - prevErr) / dt;
	double Dout = Kd * derivative;

	// Total output
	double output = Pout + Iout + Dout;

	// Restrict output to limits
	if (output > max)
		output = max;
	else if (output < min)
		output = min;

	prevErr = error;

	return output;
}

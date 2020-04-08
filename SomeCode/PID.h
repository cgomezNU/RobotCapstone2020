#pragma once
class PID
{
public:
public:
	PID();
	PID(double dt, double max, double min, double Kp, double Kd, double Ki);
	~PID();
	double calculate(double setpoint, double x);

private:
	double dt;
	double max;	
	double min;
	double Kp;
	double Kd;
	double Ki;
	double prevErr;
	double integral;
};


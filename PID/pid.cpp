#include "pid.h"

PID::PID(double kp, double ki, double kd)
    : kp(kp), ki(ki), kd(kd), prev_error(0.0), integral(0.0) {}

void PID::reset() {
    prev_error = 0.0;
    integral = 0.0;
}

double PID::out(double error, double dt) {
    integral += error * dt;
    double derivative = (error - prev_error) / dt;

    double output = kp * error + ki * integral + kd * derivative;
    prev_error = error;

    return output;
}


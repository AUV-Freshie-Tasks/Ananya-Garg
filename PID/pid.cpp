#include "pid.h"

PID::PID(double kp, double ki, double kd)
    : p(kp), i(ki), d(kd) {}

void PID::reset() {
    i.reset();
}

double PID::out(double set, double val, double dt) {
    double err = set - val;
    return p.out(err) + i.out(err, dt) + d.out(err, dt);
}

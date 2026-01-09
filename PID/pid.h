#ifndef PID_H
#define PID_H

class PID {
    double kp, ki, kd;
    double prev_error;
    double integral;

public:
    PID(double kp, double ki, double kd);

    void reset();
    double out(double error, double dt);
};

#endif


#ifndef PID_H
#define PID_H

#include "p.h"
#include "i.h"
#include "d.h"

class PID {
    P p;
    I i;
    D d;

public:
    PID(double kp, double ki, double kd);
    void reset();
    double out(double set, double val, double dt);
};

#endif

#include "d.h"

D::D(double k) {
    kd = k;
    prev = 0.0;
    first = true;
}

double D::out(double err, double dt) {
    if (first) {
        prev = err;
        first = false;
        return 0.0;
    }

    double der = (err - prev) / dt;
    prev = err;
    return kd * der;
}

#include "i.h"

I::I(double k) {
    ki = k;
    sum = 0.0;
}

void I::reset() {
    sum = 0.0;
}

double I::out(double err, double dt) {
    sum += err * dt;
    return ki * sum;
}

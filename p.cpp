#include "p.h"

P::P(double k) {
    kp = k;
}

double P::out(double err) {
    return kp * err;
}
#ifndef D_H
#define D_H

class D {
    double kd;
    double prev;
    bool first;

public:
    D(double k = 0.0);
    double out(double err, double dt);
};

#endif

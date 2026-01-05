#ifndef I_H
#define I_H

class I {
    double ki;
    double sum;

public:
    I(double k = 0.0);
    void reset();
    double out(double err, double dt);
};

#endif

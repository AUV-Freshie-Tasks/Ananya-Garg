#ifndef P_H
#define P_H

class P {
    double kp;  //how strongly the controller reacts to error.

public:
    P(double k = 0.0);
    double out(double err);
};

#endif

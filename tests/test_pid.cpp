#include <iostream>
#include <cmath>

#include "../PID/p.h"
#include "../PID/i.h"
#include "../PID/d.h"

int main() {
    P p(2.0);
    I i(0.5);
    D d(1.0);

    double setpoint = 10.0;
    double measured = 0.0;
    double dt = 0.1;

    for (int step = 0; step < 200; step++) {
        double error = setpoint - measured;

        double p_out = p.out(error);
        double i_out = i.out(error, dt);
        double d_out = d.out(error, dt);

        double output = p_out + i_out + d_out;

        measured += output * dt;   
        std::cout << step
              << " measured=" << measured
              << " output=" << output
              << "\n";
        
    }

    if (std::abs(measured - setpoint) > 2.0) {
        std::cerr << "PID test failed\n";
        return 1;
    }

    std::cout << "PID test passed\n";
    return 0;
}


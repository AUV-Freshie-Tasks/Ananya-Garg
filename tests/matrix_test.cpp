#include <iostream>
#include "../matrix/matrix.h"

int main() {
    Matrix<double> A(2,2), B(2,2);

    A(0,0)=1; A(0,1)=2;
    A(1,0)=3; A(1,1)=4;

    B(0,0)=5; B(0,1)=6;
    B(1,0)=7; B(1,1)=8;

    auto C = A + B;
    auto D = A * B;

    if (C(0,0) != 6 || D(0,0) != 19) {
        std::cerr << "Matrix test failed\n";
        return 1;
    }

    std::cout << "Matrix test passed\n";
    return 0;
}


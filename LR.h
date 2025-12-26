#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

#include "matrix.h"

class LinearRegression {
public:
    Matrix w;          // weights
    double alpha;      // learning rate
    int iters;         // number of iterations

    LinearRegression(double lr = 0.01, int steps = 1000);

    void fit(const Matrix& X, const Matrix& y);
    Matrix predict(const Matrix& X);
};

#endif

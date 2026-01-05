#ifndef LR_H
#define LR_H

#include "matrix.h"

template<typename T>
class LinearRegression {
public:
    Matrix<T> w;     // weights
    T alpha;         // learning rate
    int iters;       // iterations

    LinearRegression(T lr = 0.01, int steps = 1000);

    void fit(const Matrix<T>& X, const Matrix<T>& y);
    Matrix<T> predict(const Matrix<T>& X);
};

#include "LR.tpp"
#endif

#ifndef LR_TPP
#define LR_TPP

#include "LR.h"
#include <iostream>

using namespace std;

template<typename T>
LinearRegression<T>::LinearRegression(T lr, int steps) {
    alpha = lr;
    iters = steps;
}

template<typename T>
void LinearRegression<T>::fit(const Matrix<T>& X, const Matrix<T>& y) {

    int n = X.rows;
    int d = X.cols;

    w = Matrix<T>(d, 1);

    for (int step = 0; step < iters; step++) {

        Matrix<T> y_hat = X * w;
        Matrix<T> err(n, 1);

        for (int i = 0; i < n; i++)
            err.m[i][0] = y_hat.m[i][0] - y.m[i][0];

        Matrix<T> grad = X.transpose() * err;

        for (int i = 0; i < d; i++)
            grad.m[i][0] /= n;

        for (int i = 0; i < d; i++)
            w.m[i][0] -= alpha * grad.m[i][0];

        if (step % 100 == 0) {
            T loss = 0;
            for (int i = 0; i < n; i++)
                loss += err.m[i][0] * err.m[i][0];

            loss /= (2 * n);
            cout << "Step " << step << " | Loss = " << loss << endl;
        }
    }
}

template<typename T>
Matrix<T> LinearRegression<T>::predict(const Matrix<T>& X) {
    return X * w;
}

#endif

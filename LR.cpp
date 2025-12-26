#include "LR.h"
#include <iostream>

using namespace std;

LinearRegression::LinearRegression(double lr, int steps) {
    alpha = lr;
    iters = steps;
}

void LinearRegression::fit(const Matrix& X, const Matrix& y) {
    int n = X.rows;
    int d = X.cols;

    w = Matrix(d, 1);

    for (int step = 0; step < iters; step++) {

        
        Matrix y_hat = X * w;
        Matrix err(n, 1);

        for (int i = 0; i < n; i++)
            err.m[i][0] = y_hat.m[i][0] - y.m[i][0];

        Matrix grad = X.T() * err;
        for (int i = 0; i < d; i++)
            grad.m[i][0] /= n;

        for (int i = 0; i < d; i++)
            w.m[i][0] -= alpha * grad.m[i][0];

        
        if (step % 100 == 0) {
            double loss = 0;
            for (int i = 0; i < n; i++)
                loss += err.m[i][0] * err.m[i][0];
            loss /= (2 * n);

            cout << "Step " << step << " | Loss = " << loss << endl;
        }
    }
}

Matrix LinearRegression::predict(const Matrix& X) {
    return X * w;
}

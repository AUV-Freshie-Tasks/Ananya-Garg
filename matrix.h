#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <stdexcept>
using namespace std;

class Matrix {
public:
    int rows, cols;
    vector<vector<double>> m;

    Matrix(int r=0, int c=0);

    double& operator()(int r, int c);
    double  operator()(int r, int c) const;

    Matrix operator+(const Matrix& o) const;
    Matrix operator*(const Matrix& o) const;

    Matrix T() const;
    

    friend Matrix inverse(const Matrix& A);

private:
    void check(int r, int c) const;
};

#endif


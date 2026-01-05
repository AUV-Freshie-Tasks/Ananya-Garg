#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
using namespace std;

template<typename T>
class Matrix {

public:
    int rows, cols;
    vector<vector<T>> m;

    Matrix(int r=0, int c=0);

    T& operator()(int r, int c);
    T operator()(int r, int c) const;

    Matrix<T> operator+(const Matrix<T>& o) const;
    Matrix<T> operator*(const Matrix<T>& o) const;

    Matrix<T> T() const;

    template<typename U>
    friend Matrix<U> inverse(const Matrix<U>& A);

private:
    void check(int r, int c) const;
};

#include "matrix.tpp"
#endif

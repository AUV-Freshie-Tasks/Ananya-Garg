#ifndef MATRIX_TPP
#define MATRIX_TPP

#include "matrix.h"
#include <cmath>
#include <iostream>

using namespace std;


template<typename T>
Matrix<T>::Matrix(int r, int c)
    : rows(r), cols(c), m(r, vector<T>(c, 0)) {}


template<typename T>
void Matrix<T>::check(int r, int c) const {
    if (r < 0 || r >= rows || c < 0 || c >= cols)
        cout << "Out of bounds\n";
        return;
}


template<typename T>
T& Matrix<T>::operator()(int r, int c) {
    check(r, c);
    return m[r][c];
}


template<typename T>
T Matrix<T>::operator()(int r, int c) const {
    check(r, c);
    return m[r][c];
}


template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& o) const {

    if (rows != o.rows || cols != o.cols) {
        cout << "Size mismatch\n";
        return Matrix<T>();
    }

    Matrix<T> ans(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            ans.m[i][j] = m[i][j] + o.m[i][j];

    return ans;
}


template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& o) const {

    if (cols != o.rows) {
        cout << "Size mismatch\n";
        return Matrix<T>();
    }

    Matrix<T> ans(rows, o.cols);
    for (int i = 0; i < rows; i++)
        for (int k = 0; k < cols; k++)
            for (int j = 0; j < o.cols; j++)
                ans.m[i][j] += m[i][k] * o.m[k][j];

    return ans;
}


template<typename T>
Matrix<T> Matrix<T>::T() const {
    Matrix<T> t(cols, rows);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            t.m[j][i] = m[i][j];
    return t;
}

#endif

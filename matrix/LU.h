
#ifndef LU_H
#define LU_H

#include "matrix.h"
#include <vector>
using namespace std;

template<typename T>
struct LU {
    Matrix<T> L, U;
    vector<int> perm;
};

template<typename T>
LU<T> decomp(const Matrix<T>& A);

template<typename T>
Matrix<T> solveLU(const LU<T>& lu, const Matrix<T>& b);

#include "LU.tpp"
#endif

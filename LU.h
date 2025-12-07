#ifndef LU_H
#define LU_H

#include "Matrix.h"
#include <vector>
using namespace std;

struct LU {
    Matrix L, U;
    vector<int> perm;   // permutation vector for row swaps
};

// compute LU decomposition (with partial pivoting)
LU decomp(const Matrix& A);

// solve Ax = b using LU
Matrix solveLU(const LU& lu, const Matrix& b);

#endif

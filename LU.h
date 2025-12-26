#ifndef LU_H
#define LU_H

#include "matrix.h"
#include <vector>
using namespace std;

struct LU {
    Matrix L, U;
    vector<int> perm;   
};

LU decomp(const Matrix& A);
Matrix solveLU(const LU& lu, const Matrix& b);

#endif

#ifndef GJ_H
#define GJ_H

#include "matrix.h"

template<typename T>
Matrix<T> inverse(const Matrix<T>& A);

#include "GJ.tpp"
#endif

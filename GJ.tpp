#ifndef GJ_TPP
#define GJ_TPP

#include "GJ.h"
#include <iostream>

using namespace std;

template<typename T>
Matrix<T> inverse(const Matrix<T>& A) {

    int n = A.rows;
    Matrix<T> aug(n, 2*n);

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) aug.m[i][j] = A.m[i][j];
        for (int j=0;j<n;j++) aug.m[i][n+j] = (i == j);
    }

    for (int c=0;c<n;c++) {

        int p = c;
        for (int r=c+1;r<n;r++)
            if (abs(aug.m[r][c]) > abs(aug.m[p][c]))
                p = r;

        if (aug.m[p][c] == 0) {
            cout << "Singular matrix\n";
            return Matrix<T>();
        }

        swap(aug.m[p], aug.m[c]);

        T piv = aug.m[c][c];
        for (int j=0;j<2*n;j++)
            aug.m[c][j] /= piv;

        for (int r=0;r<n;r++) {
            if (r == c) continue;
            T f = aug.m[r][c];
            for (int j=0;j<2*n;j++)
                aug.m[r][j] -= f * aug.m[c][j];
        }
    }

    Matrix<T> inv(n,n);
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            inv.m[i][j] = aug.m[i][n+j];

    return inv;
}

#endif


#include "GaussJordan.h"
#include <cmath>
using namespace std;

Matrix inverse(const Matrix& A) {

    int n = A.rows;
    Matrix aug(n, 2*n);

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) aug.m[i][j] = A.m[i][j];
        for (int j=0;j<n;j++) aug.m[i][n+j] = (i==j);
    }

    for (int c=0;c<n;c++) {
        int p = c;
        for (int r=c+1;r<n;r++)
            if (fabs(aug.m[r][c]) > fabs(aug.m[p][c]))
                p = r;


        swap(aug.m[p], aug.m[c]);

        // Make pivot = 1
        double piv = aug.m[c][c];
        for (int j=0;j<2*n;j++)
            aug.m[c][j] /= piv;

        // Eliminate other rows
        for (int r=0;r<n;r++) {
            if (r == c) continue;
            double f = aug.m[r][c];
            for (int j=0;j<2*n;j++)
                aug.m[r][j] -= f * aug.m[c][j];
        }
    }

    Matrix inv(n,n);
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            inv.m[i][j] = aug.m[i][n+j];

    return inv;
}


#include "LU.h"
#include <cmath>

using namespace std;

LU decomp(const Matrix& A) {

    int n = A.rows;
    Matrix U = A;
    Matrix L(n,n);
    vector<int> p(n);

    for (int i=0;i<n;i++) {
        L.m[i][i] = 1;
        p[i] = i;
    }

    for (int c=0;c<n;c++) {

        int mx = c;
        for (int r=c+1;r<n;r++)
            if (abs(U.m[r][c]) > abs(U.m[mx][c]))
                mx = r;

        swap(U.m[mx], U.m[c]);
        swap(p[mx], p[c]);

        for (int j=0;j<c;j++)
            swap(L.m[mx][j], L.m[c][j]);

        for (int r=c+1;r<n;r++) {
            double mul = U.m[r][c] / U.m[c][c];
            L.m[r][c] = mul;

            for (int j=c;j<n;j++)
                U.m[r][j] -= mul * U.m[c][j];
        }
    }

    return {L, U, p};
}

Matrix solveLU(const LU& lu, const Matrix& b) {
    int n = lu.L.rows;

    Matrix pb(n,1);
    for (int i=0;i<n;i++)
        pb.m[i][0] = b.m[lu.perm[i]][0];

    Matrix y(n,1);
    for (int i=0;i<n;i++) {
        double s = pb.m[i][0];
        for (int j=0;j<i;j++) s -= lu.L.m[i][j] * y.m[j][0];
        y.m[i][0] = s;
    }

    Matrix x(n,1);
    for (int i=n-1;i>=0;i--) {
        double s = y.m[i][0];
        for (int j=i+1;j<n;j++) s -= lu.U.m[i][j] * x.m[j][0];
        x.m[i][0] = s / lu.U.m[i][i];
    }

    return x;
}


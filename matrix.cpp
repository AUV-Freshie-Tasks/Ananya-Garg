#include "matrix.h"
#include <cmath>

using namespace std;

Matrix::Matrix(int r, int c) : rows(r), cols(c), m(r, vector<double>(c, 0)) {}

void Matrix::check(int r, int c) const {
    if (r < 0 || r >= rows || c < 0 || c >= cols)
        cout << "Out of bounds\n";
        return;
}

double& Matrix::operator()(int r, int c) {
    check(r, c);
    return m[r][c];
}

double Matrix::operator()(int r, int c) const {
    check(r, c);
    return m[r][c];
}

Matrix Matrix::operator+(const Matrix& o) const {
    
    if (rows != o.rows || cols != o.cols) {
    cout << "Size mismatch\n";
    return Matrix();
}
    
    Matrix ans(rows, cols);
    for (int i=0;i<rows;i++)
        for (int j=0;j<cols;j++)
            ans.m[i][j] = m[i][j] + o.m[i][j];

    return ans;
}

Matrix Matrix::operator*(const Matrix& o) const {

    if (cols != o.rows) {
    cout << "Size mismatch\n";
    return Matrix();
}

    Matrix ans(rows, o.cols);
    for (int i=0;i<rows;i++)
        for (int k=0;k<cols;k++)
            for (int j=0;j<o.cols;j++)
                ans.m[i][j] += m[i][k] * o.m[k][j];

    return ans;
}

Matrix Matrix::T() const {
    Matrix t(cols, rows);
    for (int i=0;i<rows;i++)
        for (int j=0;j<cols;j++)
            t.m[j][i] = m[i][j];
    return t;
}


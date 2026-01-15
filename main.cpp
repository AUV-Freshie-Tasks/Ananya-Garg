#include <iostream>
#include <cmath>

#include "matrix/matrix.h"
#include "matrix/LU.h"
#include "matrix/GJ.h"
#include "matrix/LRUCache.h"
#include "matrix/LR.h"

int main() {


    // 1. Matrix Add & Multiply Test

    {
        Matrix<double> A(2, 2);
        Matrix<double> B(2, 2);

        A(0,0) = 1; A(0,1) = 2;
        A(1,0) = 3; A(1,1) = 4;

        B(0,0) = 5; B(0,1) = 6;
        B(1,0) = 7; B(1,1) = 8;

        Matrix<double> C = A + B;
        Matrix<double> D = A * B;

        std::cout << "C(0,0) = " << C(0,0) << " (expected 6)\n";
        std::cout << "D(0,0) = " << D(0,0) << " (expected 19)\n";
        std::cout << "D(1,1) = " << D(1,1) << " (expected 50)\n\n";
    }


    // 2. LU Decomposition Test

    {
        Matrix<double> A(2,2);
        A(0,0) = 4; A(0,1) = 3;
        A(1,0) = 6; A(1,1) = 3;

        LU<double> lu = decomp(A);
        Matrix<double> R = lu.L * lu.U;

        std::cout << "A(0,0) = " << A(0,0) << "\n";
        std::cout << "L*U(0,0) = " << R(0,0) << "\n";

        double detA = A(0,0)*A(1,1) - A(0,1)*A(1,0);

        double detLU = 1.0;
        for (int i = 0; i < 2; i++)
            detLU *= lu.U(i,i);

        if (std::abs(std::abs(detLU) - std::abs(detA)) < 1e-6)
            std::cout << "LU decomposition works ✅\n\n";
        else
            std::cout << "LU decomposition failed ❌\n\n";
    }


    // 3. Matrix Inverse (Gauss-Jordan)

    {
        Matrix<double> A(2,2);
        A(0,0) = 4; A(0,1) = 7;
        A(1,0) = 2; A(1,1) = 6;

        Matrix<double> invA = inverse(A);
        Matrix<double> I = A * invA;

        std::cout << "I(0,0) = " << I(0,0) << "\n";
        std::cout << "I(1,1) = " << I(1,1) << "\n";
        std::cout << "I(0,1) = " << I(0,1) << "\n";
        std::cout << "I(1,0) = " << I(1,0) << "\n";

        if ( std::abs(I(0,0) - 1.0) < 1e-6 &&
             std::abs(I(1,1) - 1.0) < 1e-6 &&
             std::abs(I(0,1))       < 1e-6 &&
             std::abs(I(1,0))       < 1e-6 )
            std::cout << "Matrix inverse works ✅\n\n";
        else
            std::cout << "Matrix inverse failed ❌\n\n";
    }


    // 4. LRU Cache Test

    {
        LRUCache cache(2);

        Matrix<double> A(2,2);
        A(0,0)=1; A(0,1)=2;
        A(1,0)=3; A(1,1)=4;

        Matrix<double> B = A;
        B(0,0)=5;

        cache.put("A", decomp(A));
        cache.put("B", decomp(B));

        cache.get("A");  

        Matrix<double> C = A;
        C(0,0)=9;
        cache.put("C", decomp(C)); 

        LU<double> luB = cache.get("B");

        if (luB.U.rows == 0 || luB.U.cols == 0)
            std::cout << "LRU Cache works\n\n";
        else
            std::cout << "LRU Cache failed\n\n";
    }

    
    // 5. Linear Regression Test
  
    {
        Matrix<double> X(4, 2);
        X(0,0) = 1; X(0,1) = 1;
        X(1,0) = 1; X(1,1) = 2;
        X(2,0) = 1; X(2,1) = 3;
        X(3,0) = 1; X(3,1) = 4;

        Matrix<double> y(4, 1);
        y(0,0) = 3;
        y(1,0) = 5;
        y(2,0) = 7;
        y(3,0) = 9;

        LinearRegression<double> lr(0.01, 2000);
        lr.fit(X, y);

        Matrix<double> x_test(1,2);
        x_test(0,0) = 1;
        x_test(0,1) = 5;

        Matrix<double> y_pred = lr.predict(x_test);

        std::cout << "Predicted y = " << y_pred(0,0)
                  << " (expected ~11)\n";

        if (std::abs(y_pred(0,0) - 11.0) < 0.5)
            std::cout << "Linear Regression works \n";
        else
            std::cout << "Linear Regression failed \n";
    }

    return 0;
}

/* #include <iostream>
#include "matrix/matrix.h"

int main() {
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
    std::cout << "D(1,1) = " << D(1,1) << " (expected 50)\n";

    return 0;
} 


#include <iostream>
#include <cmath>

#include "matrix/matrix.h"
#include "matrix/LU.h"

int main() {
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
        std::cout << "LU decomposition works ✅\n";
    else
        std::cout << "LU decomposition failed ❌\n";

    return 0;
}



#include <iostream>
#include <cmath>

#include "matrix/matrix.h"
#include "matrix/GJ.h"

int main() {
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
        std::cout << "Matrix inverse works ✅\n";
    else
        std::cout << "Matrix inverse failed ❌\n";

    return 0;
}



#include <iostream>
#include "matrix/matrix.h"
#include "matrix/LU.h"
#include "matrix/LRUCache.h"

int main() {
    LRUCache cache(2);

    Matrix<double> A(2,2);
    A(0,0)=1; A(0,1)=2;
    A(1,0)=3; A(1,1)=4;

    Matrix<double> B = A;
    B(0,0)=5;

    cache.put("A", decomp(A));
    cache.put("B", decomp(B));

    // Touch A → B becomes LRU
    cache.get("A");

    // Insert C → should evict B
    Matrix<double> C = A;
    C(0,0)=9;
    cache.put("C", decomp(C));

    // Try accessing B again
    LU<double> luB = cache.get("B");

    // If B was evicted, its LU should be empty / invalid
    if (luB.U.rows == 0 || luB.U.cols == 0)
        std::cout << "LRU Cache works ✅\n";
    else
        std::cout << "LRU Cache failed ❌\n";

    return 0;
}

*/


#include <iostream>
#include <cmath>

#include "matrix/matrix.h"
#include "matrix/LR.h"

int main() {
    // Design matrix X (4 samples, 2 features: [1, x])
    Matrix<double> X(4, 2);
    X(0,0) = 1; X(0,1) = 1;
    X(1,0) = 1; X(1,1) = 2;
    X(2,0) = 1; X(2,1) = 3;
    X(3,0) = 1; X(3,1) = 4;

    // Output vector y
    Matrix<double> y(4, 1);
    y(0,0) = 3;
    y(1,0) = 5;
    y(2,0) = 7;
    y(3,0) = 9;

    LinearRegression<double> lr(0.01, 2000);
    lr.fit(X, y);

    // Predict y = 2*5 + 1 = 11
    Matrix<double> x_test(1,2);
    x_test(0,0) = 1;
    x_test(0,1) = 5;

    Matrix<double> y_pred = lr.predict(x_test);

    std::cout << "Predicted y = " << y_pred(0,0) << " (expected ~11)\n";

    if (std::abs(y_pred(0,0) - 11.0) < 0.5)
        std::cout << "Linear Regression works ✅\n";
    else
        std::cout << "Linear Regression failed ❌\n";

    return 0;
}


#include <iostream>
#include <math.h>
using namespace std;

void shiftedPowerMethod(double **A, double *vo, double *vf,
                        double &lambda, const int n,
                        const double eps, const int U)
{

    double **Ac;
    double **Ai;
    matrixAlloc(Ac, n, n);
    matrizAlloc(Ai, n, n);
    /* step uI */
    for (int i = 0; i < n; ++i)
        for (int j; j < n; ++j)
            if (i == j)
                Ai[i][j] = A[i][j] - U;
            else
                Ai[i][j] = A[i][j];
    inversePowerMethod(Ac, vo, Lambda, n, eps);
    Lamb_f = Lambda + U;

    assign(vf, vo, n);
}

int main(int argc, char const *argv[])
{
    const int n = 5;
    const int U = 5;

    double **A = new double *[n];
    for (int i = 0; i < n; ++i)
        A[i] = new double[n];

    double vo[n] = {1, 1, 1, 1, 1};
    double lambd;
    double vf[n] = {0, 0, 0, 0, 0};
    //double A_[n][n] = {{2 / 3., 1 / 3., 1 / 3.}, {1 / 3., 4 / 3., 1 / 3.}, {1 / 3., 1 / 3., 2 / 3.}};
    //double A_[n][n] = {{5, 2, 1}, {2, 3, 1}, {1, 1, 2}};
    double A_[n][n] = {{40, 8, 4, 2, 1}, {8, 30, 12, 6, 2}, {4, 12, 20, 1, 2}, {2, 6, 1, 25, 4}, {1, 2, 2, 4, 5}};

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            A[i][j] = A_[i][j];

    shiftedPowerMethod(A, vo, vf, lambd, n, 10e-7, U);

    cout << lambd << endl;
    cout << "{";
    for (int i = 0; i < n; ++i)
        if (i != n - 1)
            cout << vo[i] << ",";
        else
            cout << vo[i];
    cout << "}" << endl;

    return 0;
}
#include "../headers/inversePowerMethod.h"
#include "../headers/powerMethod.h"

using namespace std;

int main(int argc, char const *argv[])
{
    const int n = 5;

    double **A = new double *[n];
    for (int i = 0; i < n; ++i)
        A[i] = new double[n];

    double vo1[n] = {1, 1, 1};
    double vo2[n] = {1, 1, 1};

    double lambd1;
    double lambd2;

    //double A_[n][n] = {{2 / 3., 1 / 3., 1 / 3.}, {1 / 3., 4 / 3., 1 / 3.}, {1 / 3., 1 / 3., 2 / 3.}};
    //double A_[n][n] = {{5, 2, 1}, {2, 3, 1}, {1, 1, 2}};
    double A_[n][n] = {
        {40, 8, 4, 2, 1},
        {8, 30, 12, 6, 2},
        {4, 12, 20, 1, 2},
        {2, 6, 1, 25, 4},
        {1, 2, 2, 4, 5}};
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            A[i][j] = A_[i][j];


    powerMethod(A, vo1, lambd1, n, 10e-6);
    cout << lambd1 << endl;
    cout << "{";
    for (int i = 0; i < n; ++i)
        if (i != n - 1)
            cout << vo1[i] << ",";
        else
            cout << vo1[i];
    cout << "}" << endl;

    inversePowerMethod(A, vo2, lambd2, n, 10e-6);

    cout << lambd2 << endl;
    cout << "{";
    for (int i = 0; i < n; ++i)
        if (i != n - 1)
            cout << vo2[i] << ",";
        else
            cout << vo2[i];
    cout << "}" << endl;

    return 0;
}
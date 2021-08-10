#include <iostream>
#include <math.h>
using namespace std;

void inversePowerMethod(double **A, double *vo,
                        double &lambda, const int n, const double eps)
{

    /* step 2 */
    double **a = new double *[n];
    double **l = new double *[n];
    double **u = new double *[n];
    for (int i = 0; i < n; ++i)
    {
        a[i] = new double[n];
        l[i] = new double[n];
        u[i] = new double[n];
        for (int j = 0; j < n; ++j)
            a[i][j] = A_[i][j];
    }

    LU_Decomposition(a, l, u, n)

        double lamb_old = 0.;
    lamb_new = 1.;

    double *vnew = new double[n];
    assign(vnew, vo, n); /*step 4 */
    double *vold = new double[n];

    do
    {
        /* step 5 */
        lamb_old = lamb_new;
        /* step 6 */
        assign(vold, vnew, n);
        /* step 7 */
        normalize(vnew, n);
        /* step 8 */
        double *b = new double[n];
        b[0] = 1.;
        b[1] = 6.;
        b[2] = 4.;

        double *x = LUsolver(l, u, b, n);
        cout << "{" << x[0] << "," << x[1] << "," << x[2] << "}";
        LUsolver(A, u, b, n)

            /* step 9*/
            lamb_new = dotProduct(vold, vnew, n);

        for (int i = 0; i < n; ++i)
        {
            delete[] a[i];
            delete[] l[i];
            delete[] u[i];
        }
        delete[] a;
        delete[] l;
        delete[] u;
        delete[] b;
        delete[] x;
    } while (abs(lamb_new - lamb_old) / lamb_new > eplison);

    lambda = 1 / lamb_new;
    assign(vo, vold, n);

    delete[] vnew;
    delete[] vold;
}

int main(int argc, char const *)
{
    const int n = 5;

    double **A = new double *[n];
    for (int i = 0; i < n; ++i)
        A[i] = new double[n];

    double vo[n] = {1, 1, 1, 1, 1};
    double lambd;
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

    inversePowerMethod(A, vo, lambd, n, 10e-7);

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
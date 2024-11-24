#define _USE_MATH_DEFINES 
#include <stdio.h>
#include <math.h>
#define m 3
#define n 6
int main()
{
    float A[m][n], B[m][n], C[m][n], Amax, Bmax;
    int i, j, IA, IB;
    printf_s("Work 6\nEnter the array elements A[%d][%d]:\n", m, n);
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf_s("%f", &A[i][j]);

    printf_s("\nArray B[%d][%d]:\n", m, n);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
                B[i][j] = 3 * M_PI / 2;
            else
                B[i][j] = sin(2 * (i + 1));
            printf_s("%.3f ", B[i][j]);
        }
        printf_s("\n");
    }
    Amax = A[0][0];
    IA = 0;
    Bmax = B[0][0];
    IB = 0;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (A[i][j] > Amax) {
                Amax = A[i][j];
                IA = i;
            }
        }
    }
    printf_s("\nIAmax=%d", IA + 1);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (B[i][j] > Bmax)
                Bmax = B[i][j];
                IB = i;
        }
    }
    printf_s("\nIBmax=%d", IB + 1);
    if (IA < IB - 1)
    {
        for (j = 0; j < n; j += 2)
        {
            float temp = A[IA][j];
            A[IA][j] = A[IA][j + 1];
            A[IA][j + 1] = temp;
        }
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                C[i][j] = A[i][j];
    }
    else
    {
        for (j = 0; j < n; j += 2)
        {
            float temp = B[IB][j];
            B[IB][j] = B[IB][j + 1];
            B[IB][j + 1] = temp;
        }
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                C[i][j] = B[i][j];
    }
    printf_s("\nArray C[%d][%d]:\n", m, n);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            printf_s("%.3f ", C[i][j]);
        printf_s("\n");
    }
    return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "limits.h"
#include "stdbool.h"
int f(int x)
{
    int res = INT_MAX;
    if (x < 2)
        return 0;
    if (x >= 2)
        res = min((f(x - 2) + 1), INT_MAX);
    if (x >= 5)
        res = min((f(x - 5) + 1), INT_MAX);
    if (x >= 7)
        res = min((f(x - 7) + 1), INT_MAX);
    return res;
}

int change(int *a, int m, int sizea)
{
    int *f = (int*)malloc((m + 1) * sizeof(int));
    f[0] = 0;
    int i, j;
    int n = sizea;
    for (i = 1; i <= m; i++)
    {
        f[i] = INT_MAX;
        for (j = 0; j < n; j++)
        {
            if (i >= a[j] && f[i - a[j]] != INT_MAX)
                f[i] = min(f[i - a[j]] + 1, f[i]);
        }
    }
    if (f[m] == INT_MAX)
        f[m] = -1;

    for(int i = 0;i<=f[m];i++)
    {
        for(int j = 0; j <=f[m]-i; j++)
        {
            int k = f[m] - i - j;
            if( i*a[0] + j*a[1] + k*a[2] == m)
            {
                printf("2 %d  5 %d  7 %d\n" , i, j, k);
            }
        }
    }
    return f[m];
}



int uniquePaths(int m, int n)
{
    int **f = (int **)malloc(m * sizeof(int*));
    for (int i = 0; i < m; ++i)
        f[i] = (int *)malloc(n * sizeof(int));
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i ==0 || j == 0)
                f[i][j] = 1;
            else
                f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    }
    return f[m-1][n-1];
}

bool canJump(int* a, int len)
{
    bool *f = (bool*)malloc(sizeof(bool) * len);
    f[0] = true;
    for (int j = 1; j < len; j++)
    {
        f[j] = false;
        for (int i = 0; i < j; i++)
        {
            if (f[i] && i + a[i] >= j)
            {
                f[j] = true;
                break;
            }
        }
    }
    return f[len - 1];
}

int main()
{

    int a[] = {3, 2, 1, 0, 4};
    int n = 5;
    int m = 27;
    printf("%d\n", canJump(a, n));

}
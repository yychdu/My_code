#define MAXN 1005
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "stdbool.h"
#include "math.h"
int dp[MAXN];
int cuttingRope(int n)
{
    memset(&dp, 0, sizeof(int) * (MAXN));
     dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    if (n < 4) 
        return dp[n];
    for (int i = 3; i <= n; i+=1)
        for (int j = 2; j <= i;++j)
            dp[i] = max(dp[i - j] * j, dp[i]);
    return dp[n];
}
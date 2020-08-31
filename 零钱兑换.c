#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "stdbool.h"
#include "limits.h"
#include "math.h"
int coinChange(int* coins, int coinsSize, int amount){
    // int dp[amount + 1];
    int *dp = (int *)malloc((amount + 1) * sizeof(int));
    dp[0] = 0;
    int i, j;
    for (i = 1; i <= amount; i++)
    {
        dp[i] = UCHAR_MAX;
        for (j = 0; j < coinsSize; j++)
            if (i >= coins[j])
                dp[i] = fmin(dp[i], 1 + dp[i - coins[j]]);
    }
    if (dp[amount] == UCHAR_MAX)
        return -1;
    return dp[amount];
}
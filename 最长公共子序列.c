

#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "stdbool.h"
#include "math.h"
int longestCommonSubsequence(char * text1, char * text2)
{
    int row = strlen(text1) + 1;
    int col = strlen(text2) + 1;
    int dp[row][col];
    for (int i = 0; i < row; i++)
        dp[i][0] = 0;
    for (int i = 0; i < col; i++)
        dp[0][i] = 0;
    for (int i = 1; i < row; i++)
    {
        char ch1 = text1[i - 1];
        for (int j = 0; j < col; j++)
        {
            char ch2 = text2[j - 1];
            if (ch1 == ch2)
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = fmax(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[row - 1][col - 1];
}
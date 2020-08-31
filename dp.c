#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"


int rec_opt(int *arr, int i)            //递归
{
    if (i == 0)
        return arr[0];
    else if (i == 1)
        return max(arr[0], arr[1]);
    else
    {
        int a = rec_opt(arr, i - 2) + arr[i];
        int b = rec_opt(arr, i - 1);
        return max(a, b);
    }
    
}

class Solution:
    def cuttingRope(self, n: int) -> int:
        if n == 2:
            return 1
        res = -1
        for i in range(1, n):
            res = max(res, max(i * self.cuttingRope(n - i),i * (n - i)))
        return res

作者：z1m
链接：https://leetcode-cn.com/problems/jian-sheng-zi-lcof/solution/xiang-jie-bao-li-di-gui-ji-yi-hua-ji-zhu-dong-tai-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

int dp_opt(int arr[], int size)
{
    
    int a, b, i;
    int *opt = (int *)calloc(size, sizeof(int));
    opt[0] = arr[0];
    opt[1] = max(arr[0], arr[1]);
    for (i = 2; i < size; i++)
    {
        a = opt[i - 2] + arr[i];
        b = opt[i - 1];
        opt[i] = max(a, b);
    }
    return opt[size - 1];
}

int rec_subset(int *arr, int i, int s)//第i个数字 s为加起来的结果   递归
{
    if (s == 0)
        return 1;
    else if (i == 0)
        return arr[0] == s;
    else if (arr[i] > s)
        return rec_subset(arr, i - 1, s);
    else
    {
        int a = rec_subset(arr, i - 1, s - arr[i]);
        int b = rec_subset(arr, i - 1, s);
        return a | b;
    }
}



int main() 
{
    int arr[] = {3, 34, 4, 12, 5, 2};
    int size = sizeof(arr) / sizeof(int);
    printf("%d\n", rec_subset(arr, size - 1, 9));
    printf("%d\n", rec_subset(arr, size - 1, 10));
    printf("%d\n", rec_subset(arr, size - 1, 12));
    printf("%d\n", rec_subset(arr, size - 1, 13));
    return 0;
}


#define MAXN 1005
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int dp[MAXN];
int cuttingRope(int n)
{
    memset(&dp, 0, sizeof(int) * (MAXN));
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    if (n < 4) return dp[n];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i - j] * j, dp[i]);
        }
    }
    return dp[n];
}

作者：mi-li-an
链接：https://leetcode-cn.com/problems/jian-sheng-zi-lcof/solution/c100100-by-mi-li-an-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

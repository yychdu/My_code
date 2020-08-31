#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "stdbool.h"
#include "math.h"

 #define HASH_SIZE 20000
#define  OFFSET 10000
typedef struct
{
    int val;
    int cnt;
} hash_table;

hash_table hash[HASH_SIZE];

int cmp_hash(const void *a, const void *b)
{
    return ((hash_table *)b)->cnt - ((hash_table *)a)->cnt;
}
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize)
{
    memset(hash, 0, sizeof(hash));
    *returnSize = k;
    int *res = (int *)malloc(sizeof(int) * k), i, j;
    for (i = 0; i < numsSize; i++)
    {
        hash[(nums[i] + OFFSET) % HASH_SIZE].val = nums[i];
        hash[(nums[i] + OFFSET) % HASH_SIZE].cnt++;
    }
    for (i = 0, j = 0; i < HASH_SIZE; i++)
    {
        if (hash[i].cnt)
        {
            hash[j].cnt = hash[i].cnt;
            hash[j].val = hash[i].val;
            j++;
        }
    }
    qsort(hash, j, sizeof(hash_table), cmp_hash);
    for (i = 0; i < k; i++)
        res[i] = hash[i].val;
    return res;
}

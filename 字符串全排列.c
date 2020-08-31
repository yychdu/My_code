/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 
 * （1）全排列
首先求得所有可能出现在第一个位置上的字符，即把第一个字符和后边所有的字符交换；
固定第一个字符，求后面所有字符的排列。

如abc:
第一步：将第一行数据分别和第二行和第三行数据交换
a b c
b a c
c a b

第二步：保持第一列不变，将第二行数据分别和第三行数据交换
a c b
b c a
c b a

交换完毕，显然，要用到递归的知识。

作者：feng-huo-qian-qin-lu
链接：https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/solution/c-yu-yan-quan-pai-lie-qu-zhong-by-feng-huo-qian-qi/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */


#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "stdbool.h"
int cnt = 0;
void mypermutation(char *s, char *begin, char **arr, int sz)
{
    if (*begin == '\0') 
    {
        memcpy(arr[cnt], s, sz);
        cnt++;
        return;
    }
    for (char *ch = begin; *ch != '\0'; ch++)
    {
        char temp = *ch;
        *ch = *begin;
        *begin = temp;

        mypermutation(s, begin + 1, arr, sz);

        temp = *ch;
        *ch = *begin;
        *begin = temp;
    }
}

char** permutation(char* s, int* returnSize)
{
    int sz = strlen(s);
    char **arr = NULL;
    int i;

    cnt = 0;
    *returnSize = 1;
    for (i = 1; i <= sz; i++) {
        *returnSize *= i;
    }
    arr = (char **)malloc(sizeof(char *) * (*returnSize));
    for (i = 0; i < *returnSize; i++) {
        arr[i] = (char *)malloc(sizeof(char) * (sz + 1));
        memset(arr[i], 0, sizeof(char) * (sz + 1));
    }

    mypermutation(s, s, arr, sz);

    return arr;

}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int count = 0;                              //存储数量count
//char **arr = NULL;
void swap(char* s, int i, int j)
{           //定义一个交换函数
    char tmp = s[j];
    s[j] = s[i];
    s[i] = tmp;
}

bool judge(char* s, int start, int end)
{    //当字母为abb时，全排序可能出现重复，因此需要去重
    int i;
    for (i = start; i < end; i++)
    {      //当前的数字分别与不等于它的数字交换，1不和1换，2不和2换
        if (s[i] == s[end])
            return true;
    }
    return false;
}

void perm(char* s, int p, char** arr, int len)
{     //进行全排列
    if (p == len)
    {                                  //设置停止条件，当p指向字符串的末尾时截止
        s[len] = '\0';                              //给当前s添加截止符'\0'
        memcpy(arr[count], s, len);                 //将s赋值给二维数组arr
        count++;                                    //排列数量加1
        return;
    }
    int i;
    for (i = p; i < len; i++)
    {                      //依次将每个数置于第一位
        if (judge(s, p, i))                        //判断是否重复
            continue;
        swap(s, p, i);                              //把本轮指向的数放到第一位
        perm(s, p + 1, arr, len);                   //对剩下的数进行全排列
        swap(s, p, i);                              //再把原本的第一位数换回来
    }
}

char** permutation(char* s, int* returnSize){
    int total = 1;                                  //total存储N个数的全排列情况为N!
    int len = strlen(s);
    int i;
    count = 0;
    for (i = 2; i <= len; i++){
        total *= i;
    }
    char** arr = (char**)malloc(sizeof(char*) * total);     //申请一个能够存储N!个的内存
    for (i = 0; i < total; i++){
        arr[i] = (char*)calloc(len + 1, sizeof(char));      //申请每一行存储的内存数
    }    
    perm(s, 0, arr, len);                           //进行全排列
    * returnSize = count;
    return arr;
}

// 作者：yin-jia-fan
// 链接：https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/solution/quan-pai-lie-qu-zhong-you-zhu-shi-by-yin-jia-fan/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
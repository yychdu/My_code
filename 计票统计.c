/*
输入描述:
输入候选人的人数，第二行输入候选人的名字，第三行输入投票人的人数，第四行输入投票。

输出描述:
每行输出候选人的名字和得票数量。

示例1
输入
复制
4
A B C D
8
A B C D E F G H
输出
复制
A : 1
B : 1
C : 1
D : 1
Invalid : 4
*/
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

typedef struct
{
    char name[100];
    int score;
} Candidate;

int main(int argc, char const *argv[])
{
    int Candidate_num, vote_num,j,k;
    Candidate stu[100] = {0};
        char vote_name[100]={0};
    while (scanf("%d",&Candidate_num) != EOF)
    {
        
        int Invalid = 0;
        for (size_t i = 0; i < Candidate_num; i++)
        {
            scanf("%s", stu[i].name);
        }
        scanf("%d", &vote_num);
        for (j = 0; j < vote_num; j++)
        {
            scanf("%s", vote_name);
            for (k = 0; k < Candidate_num;k++)
            {
                if (strcmp(vote_name, stu[k].name) == 0)
                {
                    stu[k].score++;
                    break;
                }
            }
            if (k == Candidate_num)
                Invalid++;
        }
        for(int i=0; i<Candidate_num; i++)
                printf("%s : %d\n",stu[i].name,stu[i].score);
        printf("Invalid : %d\n",Invalid);
        memset(stu, 0, sizeof(stu));
    }
    
    return 0;
}

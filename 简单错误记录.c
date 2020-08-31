#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "stdbool.h"
typedef struct {
    int cnt;
    int line;
    char filename[100];
} myerror_log;

int main() {
    myerror_log tmp, arr[100];
    int i, arr_cnt = 0;

    while (scanf("%s %d", tmp.filename, &tmp.line) != EOF)
    {
        char *RealName = strrchr(tmp.filename, '\\') + 1;
        if (strlen(RealName) > 16)
        {
            RealName += strlen(RealName) - 16;
            
            strcpy(tmp.filename, RealName);
            // memset(tmp.filename + strlen(RealName), 0, sizeof(tmp.filename));
        }
        else
        {
            
            strcpy(tmp.filename, RealName);
            // memset(tmp.filename + strlen(RealName), 0, sizeof(tmp.filename));
        }
        for (i = 0; i < arr_cnt; i++)
        {
            if (strcmp(arr[i].filename, tmp.filename) == 0 && arr[i].line == tmp.line)
            {
                arr[i].cnt++;
                break;
            }
        }
        if (i == arr_cnt)
        {
            tmp.cnt = 1;
            memcpy(&arr[arr_cnt], &tmp, sizeof(myerror_log));
            arr_cnt++;
        }
      
    }
    if (arr_cnt < 8)
        i = 0;
    else
        i = arr_cnt - 8;
    for (; i < arr_cnt; i++)
    {
        printf("%s %d %d\n", arr[i].filename, arr[i].line, arr[i].cnt);
    }
    return 0;
}

typedef struct {
    int num;//行数
    char str[100];
    int cnt;//错误记数次数
}error_log;
 
int err(){
    int i,len,row,times,Flag,arr_cnt;
    char str[10000];
    char *p,*q;
    error_log *tmp,*ar[10000];
 
    times = 0;
    Flag = 0;
    arr_cnt = 0;
    tmp = (error_log *)malloc(sizeof(error_log));
    while(scanf("%s %d",tmp->str,&(tmp->num)) !=EOF){
        p = strrchr(tmp->str,'\\');
        p++;
        len = strlen(p);
        if(len > 16){
            p = p+len-16;
        }
        for(i=0;i<arr_cnt;i++)
        {//比较统计数组，看是否有重复记录，有相同的直接跳出，不需要记录
            if(strcmp(ar[i]->str,p) == 0)
            {
                if(ar[i]->num == tmp->num)
                {
                    ++ar[i]->cnt;
                    break;
                }
            }
        }
        if(arr_cnt == i){
            ar[arr_cnt] = (error_log *)malloc(sizeof(error_log));
            ar[arr_cnt]->num = tmp->num;
            strcpy(ar[arr_cnt]->str, p);//复制字符串
            ar[arr_cnt]->cnt = 1;//times;
            arr_cnt ++;
        }  
    }
        if(arr_cnt<8)
            i = 0;
        else
            i = arr_cnt-8;
        for(;i<arr_cnt;i++)
            printf("%s %d %d\n",ar[i]->str,ar[i]->num,ar[i]->cnt);
 
    return 0;
}
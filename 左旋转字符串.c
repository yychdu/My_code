
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

char* reverseLeftWords(char* s, int n){
    int len = strlen(s);
    char *ans  = (char *)calloc(len*2+1,sizeof(char));

    strcpy(ans,s);
    strncat(ans,s,len);
    ans[len+n]='\0';

    return ans+n;

}


int main()
{
    char str[] = "123456";
    printf("%s\n", reverseLeftWords(str, 2));
}
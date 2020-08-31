#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
char* reverseWords(char* s){
    int len = strlen(s);
    char *ptr = s;
    char *res = (char *)calloc(len + 1, sizeof(char));
    char  buf[1000] = {0};
    // char
    int r = sscanf(ptr, "%s" , buf);
    if(r < 0) return "";
    while(r > 0)
    {
        ptr += strlen(buf) + 1;
        int lek = strlen(buf);
        memcpy(res + len - lek, buf, lek);
        len -= lek;
        if(len > 0) 
        res[--len]=' ';    
        // buf = strtok(NULL, " ");
        r = sscanf(ptr, "%s" , buf);
    }
   
    while(*res == '\0'|| *res == ' ') 
        res++; //去除翻转后开头的空格与/0
    return res;
}

int main() {
    char str[80] = "This is a pen";
    char* p = str;
    char buf[100] = "";
    int r = sscanf(p, "%s" , buf);/*
    printf("r= %d buf = %s\n", r,buf);
    p += strlen(buf) + 1;
    r = sscanf(p, "%s" , buf);
    printf("r= %d buf = %s\n", r,buf);
    p += strlen(buf) + 1;
    r = sscanf(p, "%s" , buf);
    printf("r= %d buf = %s\n", r,buf);*/

    printf("%s" ,reverseWords(str));

    return(0);
}
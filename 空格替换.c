
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"


char* replaceSpace(char* s){
  char* ch = (char *)malloc(sizeof(char) * 100000);
  int j = 0;
  char string[4] = "%20";
  char *tmp = s;
  ch[0] = '\0';
  for (int i = 0; s[i] != '\0'; i++)
  {
        if (s[i] != ' ')
        {
            j++;
            continue; 
        }
          
      // tmp[i] = '\0';
      strncat(ch, tmp, j);
      strcat(ch, string);
      tmp = s + i + 1;
      j = 0;
    }
    strcat(ch, tmp);
    return ch;
}

int main() {
    char *s = "We are happy.";
    char *str = replaceSpace(s);
    printf("%s", str);
    return 0;
}
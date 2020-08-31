

#include <stdio.h>
#include <string.h>
 
int main()
{
    char arr[1000];
    while(scanf("%s",arr)!=EOF){
        int len = strlen(arr),i,j,k,flag;
        for(i=len;i>1;i--)
        {    //子密码串长度
            for(j=0;j<=len-i;j++)
            {    //子串个数及起点位置
                flag = 1;
                for(k=j;k<j+i;k++)
                {    //子串字符是否对称
                    if(arr[k] != arr[2*j+i-1-k])
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag) break;
        }
        printf("%d\n",i);
    }
    return 0;
}

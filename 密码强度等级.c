/*密码按如下规则进行计分，并根据不同的得分为密码进行安全等级划分。

一、密码长度:

5 分: 小于等于4 个字符

10 分: 5 到7 字符

25 分: 大于等于8 个字符

二、字母:

0 分: 没有字母

10 分: 全都是小（大）写字母

20 分: 大小写混合字母

三、数字:

0 分: 没有数字

10 分: 1 个数字

20 分: 大于1 个数字

四、符号:

0 分: 没有符号

10 分: 1 个符号

25 分: 大于1 个符号

五、奖励:

2 分: 字母和数字

3 分: 字母、数字和符号

5 分: 大小写字母、数字和符号

最后的评分标准:

>= 90: 非常安全

>= 80: 安全（Secure）

>= 70: 非常强

>= 60: 强（Strong）

>= 50: 一般（Average）

>= 25: 弱（Weak）

>= 0:  非常弱


对应输出为：

VERY_SECURE

SECURE,

VERY_STRONG,

STRONG,

AVERAGE,

WEAK,

VERY_WEAK,


请根据输入的密码字符串，进行安全评定。

注：

字母：a-z, A-Z

数字：-9

符号包含如下： (ASCII码表可以在UltraEdit的菜单view->ASCII Table查看)

!"#$%&'()*+,-./     (ASCII码：x21~0x2F)

:;<=>?@             (ASCII<=><=><=><=><=>码：x3A~0x40)

[\]^_`              (ASCII码：x5B~0x60)

{|}~                (ASCII码：x7B~0x7E)




输入描述:
输入一个string的密码

输出描述:
输出密码等级

示例1
输入
复制
38$@NoNoNo
输出
复制
VERY_SECURE
*/

#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

int main(int argc, char const *argv[])
{
    char str[1000], score = 0, lower = 0, digit = 0, upper = 0, chr = 0;
    
    while( gets(str))
    {
        if (strlen(str) <= 4)
            score += 5;
        else if (strlen(str) > 4 && strlen(str) < 8)
            score += 10;
        else
            score += 25;
        for (size_t i = 0; i < strlen(str); i++)
        {
            if (isdigit(str[i]))
                digit++;
            else if (islower(str[i]))
                lower++;
            else if (isupper(str[i]))
                upper++;
            else
                chr++;
        }
        if (digit == 1)
            score += 10;
        else if (digit >= 1)
            score += 25;
        if ((lower == 0 && upper > 0) || (upper == 0 && lower > 0))
            score += 10;
        else if (upper > 0 && lower > 0)
            score += 25;
        
        if (chr == 1)
            score += 10;
        else if (chr > 1)
            score += 25;
        
        if (score >= 90)
            puts("VERY_SECURE");
        else if (score >= 80)
            puts("SECURE");
        else if (score >= 70)
            puts("VERY_STRONG");
        else if (score >= 60)
            puts("STRONG");
        else if (score >= 50)
            puts("AVERAGE");
        else if (score >= 25)
            puts("WEAK");
        else  if  (score >= 0)
            puts("VERY_WEAK");
        continue;
    }
    
    return 0;
}

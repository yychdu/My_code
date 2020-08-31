
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "limits.h"
#include "math.h"
#include "stdbool.h"
/*----------------------------------------------------------------
请实现支持'?'and'*'.的通配符模式匹配
'?' 可以匹配任何单个字符。
'*' 可以匹配任何字符序列（包括空序列）。
返回两个字符串是否匹配
函数声明为：
bool isMatch(const char *s, const char *p)
下面给出一些样例：
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
aab *b
*/
bool isMatch(const char *s, const char *p)
{
    int i = 0, j = 0, istar = -1, jstar = -1;
    while (s[i])
    {
        if (p[j] && (p[j] == s[i] || p[j] == '?'))
            i++, j++;
        else if (p[j] && p[j] == '*')
        {
            istar = i;
            jstar = j++;
        }
        else if (istar >= 0)
        {
            i = ++istar;
            j = jstar + 1;
        }
        else
            return false;
    }
    while(p[j] != '\0' && p[j] == '*')
        j++;
    return p[j]=='\0';
}


// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/wildcard-matching/solution/tong-pei-fu-pi-pei-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
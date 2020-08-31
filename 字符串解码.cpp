#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "stdbool.h"
#include <string>
#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        int len = s.length();
        int num = 0;
        string res = "";
        stack<int> nums;
        stack<string> strs;
        for (int i = 0; i < len; i++) 
        {
            if (isdigit(s[i]))
                num = num * 10 + s[i] - '0';
            else if (isalpha(s[i]))
                res += s[i];
            else if (s[i] == '[')
            {
                nums.push(num);
                num = 0;
                strs.push(res);
                res = "";
            }
            else
            {
                for (int j = 0; j < nums.top(); j++)
                    strs.top() += res;
                nums.pop();
                res = strs.top();
                strs.pop();
            }
            
        }
        return res;
    }
};
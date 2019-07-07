Algorithms
=========

----------------------------------

# Problems 8 String to Integer (atoi) 

``````
// Source : https://oj.leetcode.com/problems/string-to-integer-atoi/
// Refer.  : https://www.cnblogs.com/lca1826/p/6361310.html
// Author : ioMayday
// Date   : 2019-07

class Solution {  
public:
int myAtoi(string str) {
        
        int len = str.length(); 
        
        if(len==0)  return 0; //字符串为空情况
        
    
        long long ans=0; //为便于后面比较 INT_MAx，这里用一个长整型变量
        int i=0,flag=1;  //flag 默认正数为1 负数为-1
        
        while(str[i] != '\0' && str[i] == ' ') //空格预处理
            ++i;
       
        if(str[i]=='+'||str[i]=='-') //取空格后的正负符号
        {
            if (str[i]=='-')   flag = -1;
            ++i;
        }
        
        while(str[i] != '\0') //取所有元素，直到换行符结束
        {
            if (str[i]>='0' && str[i]<='9') //取0-9之间的字符
            {
                ans = ans*10 + str[i] - '0'; //由于str[i]为字符，务必要有 str[i] - '0' 得到数值
                if (ans > INT_MAX)
                    if (1 == flag)  //千万注意别写成 flag = 1
                        return INT_MAX;
                    else
                        return INT_MIN;
            }
            else break; //遇到非数字字符则退出while循环
            
            ++i;            
        }
        
        ans = ans*flag;  //加上正负
        
        return (int)ans; //强制转换类型      
        
    }
};
``````

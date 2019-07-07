Algorithms C++ Code
=========

----------------------------------

# Problems 1 : Two Sum
````
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int cnt = nums.size();
        
        vector<int> temp; //如果下标都是返回的个数，则表示无解
                      
        for (int i=0; i<cnt-1; i++)
        {
            for (int j=i+1; j<cnt; j++)
            {
                if (target == nums[i]+ nums[j])
                {
                    temp.push_back(i);
                    temp.push_back(j);   
                }
            }     
        }
        
    return temp;    
    }
};
````

# Problems 2 : Add Two Numbers
````
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if (l1 == NULL && l2 == NULL) //判空
            return NULL;
        
        ListNode* temp = new ListNode(-1); //初始化为0
        ListNode* head = temp; // ListNode temp = new ListNode(0) 不加星号编译不通过，不是指针 
        int sum = 0;
        int carry = 0;
        
        while (l1 != NULL && l2  != NULL)
        {            
            sum = l1->val+l2->val+carry;
            temp->next = new ListNode(sum % 10); //指针移向高位
            temp = temp->next;
            carry = sum / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while (l1 != NULL) //l2为空时跳出来的，l1高位还有数
        {
            sum = l1->val+carry;
            temp->next = new ListNode(sum % 10); //动态建立下个节点及初始值
            temp = temp->next;
            carry = sum / 10;
            l1 = l1->next; 
        }
        
        while (l2 != NULL) //l1为空时跳出来的，l2高位还有数
        {
            sum = l2->val+carry;
            temp->next = new ListNode(sum % 10); //动态建立下个节点及初始值
            temp = temp->next;
            carry = sum / 10;
            l2 = l2->next;   
        }
        
        //循环完后若carry值不为0，那么表示还得进一位高位值
        if (carry != 0 )
            temp->next = new ListNode(carry);
        
       return head->next;       
    }
};
````

# Problems 3 : 	Longest Substring Without Repeating Characters  
````
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
    // 暴力搜索改良版，O（N^2）
    int index = 0; //记录字符串临时起始位置
    int len_s = s.size();
    int len = 1;
    
    if (len_s == 0 || len_s == 1)   //排除掉0个或1个字符情况
        return len_s;
    
    for (int i=1; i<len_s; i++) //依次从第二个元素向后选择
    {
        
        for (int j=i-1; j>=index; --j) //j始终小于当前大循环里的i
        {
            if (s[i] == s[j])
            {
                index = j+1;               
                break;
            }
            
            if (len < i-j+1) //i-j+1为当前不重复子字符串的长度
                len = i-j+1;           
            
        }                  
        
    }
    
   return len;       
        
 }
};
````

# Problems 4 :
````

````

# Problems 5 :
````

````

# Problems 6 :
````

````

# Problems 7 :
````

````

# Problems 8 : String to Integer (atoi) 

``````
// Source : https://oj.leetcode.com/problems/string-to-integer-atoi/
// Refer. : https://www.cnblogs.com/lca1826/p/6361310.html
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

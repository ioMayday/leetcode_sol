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

# Problems 4 : 	Median of Two Sorted Arrays 
````
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Divide conquere. We know these two arrays are sorted.
        
        vector<int> Temp;        
        int i=0,j=0;
             
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        while (i<len1 && j<len2)
        {
            if (nums1[i] <= nums2[j])
                Temp.push_back(nums1[i++]);                              
            else
                Temp.push_back(nums2[j++]);      
        }
        
        // nums1 is empty but nums2 not
        while (j<len2)
             Temp.push_back(nums2[j++]);
        
        // nums2 is empty but nums1 not
        while (i<len1)
             Temp.push_back(nums1[i++]);
                
        // Find the median number
        int mid_index = Temp.size()/2;
        
        return (Temp.size()%2 == 0)? ((Temp[mid_index]+Temp[mid_index-1])/2.0) : Temp[mid_index];   //judge the length is odd or even number   
                
    }
};
````

# Problems 5 : Longest Palindromic Substring
````
class Solution {
public:
    string longestPalindrome(string s) { //找寻最长的回文字符串
        
        int start=0,maxLen=1,Len=s.size();
        
        if(Len < 2) return s; //字符串小于等于1时直接返回
        
        for (int i=0; i<Len;) //i设为新的回文字符串中间位置处
        {
            if (Len-i <= maxLen/2) break; 
            int j=i,k=i;
            
            while (k<Len-1 && s[k]==s[k+1]) k++; //下标k不超过字符串长度
            i = k+1; //当连续出现同一字母时，i指向重复字母的下一位。若没有，也自动加1
            
            while(j>0 && k<Len-1 && s[j-1]==s[k+1]) //比较的是j前一位和k一位，比较失效时，取的j，k有效位
            {
                j--;  k++;          //比较以中点i为中心的回文串首尾字母是否相等      
            }
            
            int newLen = k-j+1;//新的回文串长度
            if(newLen>maxLen) //如果比原回文串长，则赋新值
            {
                maxLen=newLen;
                start=j;
            }
                        
        }
        
        return s.substr(start,maxLen); //最大回文子串，从start开始，取maxLen个元素
               
    }
};
````

# Problems 6 : ZigZag Conversion 
````
class Solution {
public:
    string convert(string s, int numRows) {
        
        if (numRows <= 0)  //排除行数不大于0的
            return "";           
        
        if (numRows>=s.length() || numRows==1) //排除行数等于1或行数大于等于字符串长度的
            return s;
        
        int len = s.length();
        string sbuf;
        
        for(int i=0; i<numRows; ++i)  //分行读取
        {
            int start = i; //每行字符串起始位置，随i而变化
            for(int j=1; start<len;++j) //每行读取超出末尾元素停止
            {
                sbuf.push_back(s[start]);
                //第一行和最后一行
                if(i==0 || i==numRows-1)
                {
                    start = start+2*numRows-2;
                }
                else {// 中间行，按矩阵排列，其他位置视为为0
                    if(j%2 ==1)
                        start = start+2*(numRows-i-1); //奇数列，列数从0开始，
                    else
                        start = start+2*i;//偶数列
                }
                
            }
            
        }
        
        return sbuf;
        
    }
};

//Reference links：the code of JAVA from CSDN
//https://blog.csdn.net/pistolove/article/details/41408021
//Thanks to pistolove!
````

# Problems 7 : Reverse Integer    
````
class Solution {
public:
    int reverse(int x) {
        
    if (x > INT_MAX || x < INT_MIN || x==0) return 0; //INT_MAX等都宏定义好了，为整数型的最大值
        
        int RevNum = 0;
       
        while (x != 0)
        {
            if ((RevNum > INT_MAX/10 || RevNum < INT_MIN/10) && ((x > 0 && (x % 10 <= 7)) || x < 0 && (x % 10 >= -8))) return 0; //如果最后移到最高位前的数将溢位，则返回0
            RevNum = RevNum*10 + x%10; //取低位数给RevNum，之后累乘10，放到高位去
            x = x/10;                 
        }

        return RevNum;
        
    }
};
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

# Problems 9 : Palindrome Number

``````
class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x >=0 && x < 10) return true;
        if (x < 0 || x%10 == 0) return false; //exclude ex2 and ex3
        
        
        int RevNum = 0;
        int temp = x;
        
        while (temp!=0)
        {
            if ((RevNum > INT_MAX/10 || RevNum < INT_MIN/10) && ((temp > 0 && (temp % 10 <= 7)) || temp < 0 && (temp % 10 >= -8))) return false; 
          RevNum = RevNum*10+ temp%10;
          temp = temp/10;
        }
        
        if (x==RevNum)
            return true;
        else 
            return false;
        
    }
};
``````


# Problems 10 : Regular Expression Matching
方法一
``````
// C code 参考LeetCode题解 第三章字符串 3.6节
bool isMatch(char * s, char * p){
    if (*p == '\0') return *s == '\0'; //终止条件 p完后，若s也对比完则true，否则false
    
    if (*(p+1) != '*') { //如果下个字符不是 *
        if (*p==*s || (*p=='.' && *s!='\0') ) return isMatch(s+1,p+1); //匹配条件是 字符相等 或者 p对应为.且s非末尾
        else 
            return false;
    }
    else { //下个字符是 *
        while ( (*p==*s) || (*p=='.' && *s!='\0') ) //处理完一个 _* 类的p中字符串
        {
            if ( isMatch(s,p+2) ) return true; //直接将_*当消除匹配
            s++;
        }
        return isMatch(s,p+2); //处理完_*后，递归进入*的下一位继续匹配
    } 

}
``````

方法二
``````
// C code 没看太懂
bool isMatch(char * s, char * p){
    
 
        for (char c=*p; c != '\0'; ++s, c=*p) {
            if (p[1] != '*') ++p;
            else if (isMatch(s, p+2)) return true;
            if (!(c == *s || (c == '.' && *s != '\0'))) return false;
        }
        return *s == '\0';

}
``````

方法三
``````
// C++ code 效率低下 但代码简洁
class Solution {
public:
    bool isMatch(string s, string p) {//通过substr,让每次的比较只集中在前两个字符
        if(p.empty()) return s.empty();
        if(p[1]=='*') return (isMatch(s,p.substr(2)) || ((p[0]==s[0]||p[0]=='.') && !s.empty() && isMatch(s.substr(1),p)));
        else return !s.empty()&&(p[0]==s[0]||p[0]=='.') && isMatch(s.substr(1),p.substr(1));
    }
};

//https://blog.csdn.net/qq_40280096/article/details/82117696
``````




# Problems 11 : 

方法一 暴力搜索
``````
class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() < 2) return 0;
        
        int h=0,maxV=0,curV;
        
        for (int i=0;i<height.size();i++) { //原始遍历
            
            for (int j=i+1;j<height.size();j++) {
                h = height[j]<height[i]? height[j] : height[i];
                curV = (j-i)*h;
                
                if (curV > maxV) maxV=curV;        
            }        
        }
        
        return maxV;
           
    }
};
``````
**方法二**
思路：
以底边（从左到右）最长为迭代的起点，哪一侧的木板短，哪一侧的侧边便往里收缩（因为这边已经是瓶颈了，换一个侧壁后容积增大的可能性较大）
注意到如果从取值的两端向中间遍历，若是两条垂直线中的一条短于另一条，则之后保留该条垂直线的所有容器，容量都不可能超过该容器，因为随着遍历向中间进行，容器的长度在缩小，而这样遍历得到的容器的高度不可能超过初始高度，从而体积也更小。因此之后的遍历若想得到更大的容器，则一定不能保留较短的那条垂直线。
这导出了如下算法：遍历由列表的两端向中间进行，每次较短的那条垂直线向中间移动一个单位，由对应的另一条垂直线代替；每次计算对应容器的容积，保留这些容积中的最大值；当两条垂直线靠在一起时，遍历结束，此时已经得到了可能的最大容积。这种算法只需进行一层循环，时间复杂度为O(n)，因而更好。
每个容器的面积，取决于最短的木板。
**参考书：LeetCode题解 第十二章 贪心法 12.6**
``````
class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() < 2) return 0;
        
        //从最外层往里收，桶的底边长越来越小，高由两侧最短边决定
        // 先满足底边最长，再按侧壁条件，满足容量，遍历一边后即可找出最大容量
        int start=0,result=INT_MIN;
        int end = height.size()-1;
        
        while (start<end) {
           
            //求得height[start],height[end]两侧壁中高度较小一侧的，最大底边下的最大容量
            result = max( result,  min(height[start],height[end])*(end-start)  ); //用到比较求最大最小值函数,<algorithm>
            
            if (height[start] <= height[end]) start++; //缩小底边，增加高度
            else end--; //往内缩底边，增加高度
                      
        }
        
        return result;

    }
};
``````

# Problems 12 : Palindrome Number

``````

``````

# Problems 13 : Palindrome Number

``````

``````
# Problems 10 : Palindrome Number

``````

``````

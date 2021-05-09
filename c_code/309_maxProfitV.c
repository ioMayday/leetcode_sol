#include limits.h

 采用状态机来遍历
 买前必须卖完，买完再卖出去才算一笔交易
 模板 
状态转移方程：
dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + price[i]);
dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - price[i]);

Base Case
dp[-1][k][0] = 0;
dp[-1][k][1] = -Infinity; 不可能
dp[i][0][0] = 0;
dp[i][0][1] = -Infinity;

 output dp[n - 1][k][0]
#define max(a, b) (a)  (b)  (a)  (b)
#define MAX_K_NUM 2
 冷冻期一天条件转化为：一旦发现卖出，则跳过下一天循环  = 此思路不对，会导致无法推广转移矩阵，得到所有可能情况
 正确做法，修改状态转移方程，买入时，从前两天不持有状态的数组转移过来，i-1 变为 i-2
int maxProfit(int prices, int pricesSize)
{
     k = +infinity
    int dp_i_0 = 0;
    int dp_i_1 = INT_MIN;
    int i;
    int pre_dp_i_0 = 0;
    for (i = 0; i  pricesSize; i++) {
         dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + price[i]);  不动或卖出
         dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 2][k - 1][0] - price[i]);  不动或买入
        int tmp = dp_i_0;  更新前
        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);  当前更新后
        dp_i_1 = max(dp_i_1, pre_dp_i_0 - prices[i]);
        pre_dp_i_0 = tmp;  下次循环用时，就变成了前两天的
    }
    return dp_i_0;
}
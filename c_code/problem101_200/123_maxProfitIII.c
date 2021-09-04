#include <limits.h>

// 采用状态机来遍历
// 买前必须卖完，买完再卖出去才算一笔交易
/**** 模板 **********
状态转移方程：
dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + price[i]);
dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - price[i]);

Base Case:
dp[-1][k][0] = 0;
dp[-1][k][1] = -Infinity; //不可能
dp[i][0][0] = 0;
dp[i][0][1] = -Infinity;
********************/
// output: dp[n - 1][k][0]
#define max(a, b) (a) > (b) ? (a) : (b)
#define MAX_K_NUM 2
int maxProfit(int* prices, int pricesSize){
    // k = 2
    int dp_i_0[MAX_K_NUM + 1] = {0};
    int dp_i_1[MAX_K_NUM + 1] = {INT_MIN, INT_MIN, INT_MIN};  // 注意 {INT_MIN}，不能达到全初始化为最小值的目的，只有第一个最小值，其他都补的0
    int i;
    for (i = 0; i < pricesSize; i++) {
        // dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + price[i]);
        // dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - price[i]);
        dp_i_0[0] = 0; // dp[i][0][0] = 0;
        dp_i_1[0] = INT_MIN; // dp[i][0][1] = -Infinity;
        int j;
        for (j = 1; j < MAX_K_NUM + 1; j++) {
            dp_i_0[j] = max(dp_i_0[j], dp_i_1[j] + prices[i]);
            dp_i_1[j] = max(dp_i_1[j], dp_i_0[j - 1] - prices[i]);
        }
    }
    return dp_i_0[MAX_K_NUM];
}
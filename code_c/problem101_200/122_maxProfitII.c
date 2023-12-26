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
int maxProfit(int* prices, int pricesSize){
    // k = infinity
    int dp_i_0 = 0;
    int dp_i_1 = INT_MIN;
    int i;
    for (i = 0; i < pricesSize; i++) {
        // dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + price[i]);
        // dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k][0] - price[i]); // k无穷大时，k-1和k看作相等
        int tmp_dp_i_0 = dp_i_0;
        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
        dp_i_1 = max(dp_i_1, tmp_dp_i_0 - prices[i]);
    }
    return dp_i_0;
}
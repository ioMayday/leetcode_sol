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
int maxProfit(int* prices, int pricesSize, int fee)
{
    // k = +infinity
    int dp_i_0 = 0;
    int dp_i_1 = INT_MIN;
    int i;
    for (i = 0; i < pricesSize; i++) {
        // dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + price[i] - fee); // 卖出时才扣手续费
        // dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - price[i]);
        int tmp_dp_i_0 = dp_i_0;
        // 注意防止超过int最小值, 如 INT_MIN + 1 - 2 就溢出了
        int tmp = ((long long)dp_i_1 + prices[i] - fee < INT_MIN) ? INT_MIN : (dp_i_1 + prices[i] - fee);
        dp_i_0 = max(dp_i_0, tmp);
        dp_i_1 = max(dp_i_1, tmp_dp_i_0 - prices[i]);
    }
    return max(dp_i_0, dp_i_1);
}
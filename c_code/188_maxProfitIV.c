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
// #define MAX_K_NUM 2

int maxProfit_k_inf(int* prices, int pricesSize){
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

int maxProfit(int k, int* prices, int pricesSize) {
    //买入卖出要两天才算一次操作，当k大于数组长度的一半时，就相当于操作次数不限
    if (k > pricesSize / 2) // 解决超出时间限制的问题
        return maxProfit_k_inf(prices, pricesSize);

    // k = 2
    // int dp_i_0[MAX_K_NUM + 1] = {0};
    // int dp_i_1[MAX_K_NUM + 1] = {INT_MIN, INT_MIN, INT_MIN};
    // 动态分配
    int *dp_i_0 = calloc(k + 1, sizeof(int)); // 申请内存，并初始化为0
    if (dp_i_0 == NULL) { return 0; }
    int *dp_i_1 = calloc(k + 1, sizeof(int));
    if (dp_i_1 == NULL) { return 0; }
    unsigned int i;
    for (i = 0; i < k + 1; i++) {
        dp_i_1[i] = INT_MIN;
    }

    for (i = 0; i < pricesSize; i++) {
        // dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + price[i]);
        // dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - price[i]);
        dp_i_0[0] = 0; // dp[i][0][0] = 0;
        dp_i_1[0] = INT_MIN; // dp[i][0][1] = -Infinity;
        unsigned int j;
        for (j = 1; j < k + 1; j++) {
            dp_i_0[j] = max(dp_i_0[j], dp_i_1[j] + prices[i]);
            dp_i_1[j] = max(dp_i_1[j], dp_i_0[j - 1] - prices[i]);
        }
    }
    int result = dp_i_0[k];
    free(dp_i_0);
    free(dp_i_1);
    return result;
}
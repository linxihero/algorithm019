/*
 * @lc app=leetcode.cn id=122 lang=c
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start

// 贪心算法
int maxProfit(int* prices, int pricesSize) {
    int sum = 0;
    for (int i = 0; i < pricesSize - 1; i++) {
        int m = prices[i+1] - prices[i];
        if (m >= 0) {
            sum += m;
            continue;
        }
    }
    return sum;
}


// @lc code=end


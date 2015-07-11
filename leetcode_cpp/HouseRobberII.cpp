/*
 * House Robber II 
 *
 * Note: This is an extension of House Robber.
 *
 * After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.
 *
 * Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 *
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n <= 1) {
            return nums[0];
        }
        vector<vector<int>> dp(n, vector<int>(2));
        int ans = 0;

        // case 1: nums[0] is taken
        dp[0][1] = nums[0];
        dp[1][0] = dp[0][1];
        dp[1][1] = 0;
        for (int i = 2; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i];
        }
        ans = dp[n - 1][0];

        // case 2: nums[0] is not taken
        dp = vector<vector<int>>(n, vector<int>(2));
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i];
        }
        ans = max(ans, max(dp[n - 1][0], dp[n - 1][1]));
        return ans;
    }
};

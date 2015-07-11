/*
 * House Robber II
 *
 * Note: This is an extension of House Robber.
 *
 * After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.
 *
 * Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 */

public class Solution {
    public int rob(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        if (nums.length == 1) {
            return nums[0];
        }
        int n = nums.length;
        int[] dp = new int[n];
        int ans = 0;

        // case 1: nums[0] is taken
        dp[0] = nums[0];
        dp[1] = nums[0];

        for (int i = 2; i < n; ++i) {
            dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        ans = dp[n - 2];

        // case 2: nums[0] is not taken
        dp[0] = 0;
        dp[1] = nums[1];
        for (int i = 2; i < n; ++i) {
            dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        
        ans = Math.max(ans, dp[n - 1]);
        return ans;
    }
}

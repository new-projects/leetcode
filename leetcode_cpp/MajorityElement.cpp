/*
 * Majority Element
 *
 * Given an array of size n, find the majority element. The majority element is the element that appears more than int(n/2) times.
 *
 * You may assume that the array is non-empty and the majority element always exist in the array.
 *
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cur = nums[0];
        int count = 1;
        for (int i = 1; i < n; ++i) {
            if (count == 0) {
                cur = nums[i];
                ++count;
            } else if (cur == nums[i]) {
                ++count;
            } else {
                --count;
            }
        }
        return cur;
    }
};

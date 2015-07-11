/*
 * Summary Ranges
 *
 * Given a sorted integer array without duplicates, return the summary of its ranges.
 *
 * For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 *
 */

class Solution {
    public:
        
        vector<string> summaryRanges(vector<int>& nums) {
            int n = nums.size();
            vector<string> result;
            for (int i = 0; i < n; ) {
                int j = i + 1;
                while (j < n && nums[j] == nums[j - 1] + 1) {
                    ++j;
                }
                if (j > i + 1) {
                    result.push_back(to_string(nums[i]) + "->" + to_string(nums[j - 1]));
                } else {
                    result.push_back(to_string(nums[i]));
                }
                i = j;
            }
            return result;
        }
};

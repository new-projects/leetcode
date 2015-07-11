/*
 * Majority Element II
 *
 * Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
 */

public class Solution {
    public List<Integer> majorityElement(int[] nums) {
        return majorityElement(nums, 3);
    }

    // more than int(n/k) times
    public List<Integer> majorityElement(int[] nums, int k) {
        HashMap<Integer, Integer> count = new HashMap<Integer, Integer>();
        int n = nums.length;

        for (int i = 0; i < n; ++i) {
            if (count.containsKey(nums[i])) {
                count.put(nums[i], count.get(nums[i]) + 1);
            } else {
                count.put(nums[i], 1);
            }
            if (count.size() == k) {
                for(Iterator<Map.Entry<Integer, Integer>> it = count.entrySet().iterator(); it.hasNext(); ) {
                    Map.Entry<Integer, Integer> entry = it.next();
                    entry.setValue(entry.getValue() - 1);
                    if (entry.getValue() == 0) {
                        it.remove();
                    }
                }
            }
        }

        for (Map.Entry<Integer, Integer> entry : count.entrySet()) {
            entry.setValue(0);
        }
        List<Integer> result = new ArrayList<Integer>();
        for (int i = 0; i < n; ++i) {
            if (count.containsKey(nums[i])) {
                count.put(nums[i], count.get(nums[i]) + 1);
                if (count.get(nums[i]) == n / k + 1) {
                    result.add(nums[i]);
                }
            }
        }
        return result;
    }
}

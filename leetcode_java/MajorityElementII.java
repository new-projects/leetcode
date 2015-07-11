/*
 * Majority Element II
 *
 * Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
 */

public class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> result = new ArrayList<Integer>();
        if (nums == null || nums.length == 0) {
            return result;
        }
        int n1 = 0, n2 = 0;
        int c1 = 0, c2 = 0;
        int n = nums.length;

        for (int i = 0; i < n; ++i) {
            if (n1 == nums[i]) {
                ++c1;
            } else if (n2 == nums[i]) {
                ++c2;
            } else if (c1 == 0) {
                n1 = nums[i];
                c1 = 1;
            } else if (c2 == 0) {
                n2 = nums[i];
                c2 = 1;
            } else {
                --c1;
                --c2;
            }
        }

        c1 = c2 = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == n1) {
                ++c1;
            } else if (nums[i] == n2) {
                ++c2;
            }
        }
        if (c1 > n / 3) result.add(n1);
        if (c2 > n / 3) result.add(n2);
        return result;
    }
}

// generic algorithm for k majority elment (occurs more than int(n/k) times)  problem.
// Complexity: NlogK
// Space: K
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

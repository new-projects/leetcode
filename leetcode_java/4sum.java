import java.util.*;

public class Solution {
    public ArrayList<ArrayList<Integer>> fourSum(int[] num, int target) {
        int n = num.length;
        Arrays.sort(num);
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
        for (int i = 0; i < num.length; ++i) {
            if (i > 0 && num[i] == num[i - 1]) continue;
            for (int j = i + 1; j < num.length; ++j) {
                if (j > i + 1 && num[j] == num[j - 1]) continue;
                int l = j + 1, r = num.length - 1;
                while (l < r) {
                    int sum = num[i] + num[j] + num[l] + num[r];
                    if (sum == target) {
                        ArrayList<Integer> solution = new ArrayList<Integer>();
                        solution.add(num[i]);
                        solution.add(num[j]);
                        solution.add(num[l]);
                        solution.add(num[r]);
                        result.add(solution);
                        ++l;
                        while (l < r && num[l] == num[l - 1]) ++l;
                        --r;
                        while (l < r && num[r] == num[r + 1]) --r;
                    } else if (sum > target) {
                        --r;
                    } else {
                        ++l;
                    }
                }
            }
        }
        return result;
    }
}

public class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        Set<Character> set = new HashSet<>();
        int i = 0;
        int j = 0;
        int ans = 0;
        while (j < s.length()) {
            char ch = s.charAt(j);
            if (!set.contains(ch)) {
                set.add(ch);
                j++;
                ans = Math.max(ans, j - i);
            } else {
                set.remove(s.charAt(i++));
            }
        }
        return ans;
    }
}

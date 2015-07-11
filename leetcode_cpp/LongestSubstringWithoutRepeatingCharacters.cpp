/*
Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating
characters. For example, the longest substring without repeating letters for
"abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is
"b", with the length of 1.
*/
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int cnt[256] = { 0 };
    int res = 0;
    for (int i = 0, j = 0; i < s.size(); ++i) {
      ++cnt[s[i]];
      while (cnt[s[i]] > 1) {
        --cnt[s[j++]];
      }
      res = max(res, i - j + 1);
    }
    return res;
  }
};

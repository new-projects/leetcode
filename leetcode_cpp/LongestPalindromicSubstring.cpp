/*
Longest Palindromic Substring

Given a string S, find the longest palindromic substring in S. You may assume
that the maximum length of S is 1000, and there exists one unique longest
palindromic substring.
*/

class Solution {
public:
  string longestPalindrome(string s) {
    int maxLen = 0;
    int startIndex = 0;
    for (int i = 0; i < s.size(); ++i) {
      // one center
      int l = i, r = i;
      while (l >= 0 && r < s.size() && s[l] == s[r]) {
        --l;
        ++r;
      }
      ++l, --r;
      if (maxLen < r - l + 1) {
        maxLen = r - l + 1;
        startIndex = l;
      }
      // two centers
      l = i, r = i + 1;
      while (l >= 0 && r < s.size() && s[l] == s[r]) {
        --l;
        ++r;
      }
      ++l, --r;
      if (l < r && s[l] == s[r] && maxLen < r - l + 1) {
        maxLen = r - l + 1;
        startIndex = l;
      }
    }
    return s.substr(startIndex, maxLen);
  }
};


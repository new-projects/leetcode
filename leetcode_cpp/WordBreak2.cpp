/**
 * Word Break
 *
 * Given a string s and a dictionary of words dict, determine if s can be
 * segmented into a space-separated sequence of one or more dictionary words.
 *
 * For example, given
 * s = "leetcode",
 * dict = ["leet", "code"].
 *
 * Return true because "leetcode" can be segmented as "leet code".
 */
class Solution {
public:
  bool wordBreak(string s, unordered_set<string> &dict) {
    if (s.empty()) return false;
    int n = s.size();
    vector<bool> possible(n + 1, false);
    possible[n] = true;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = i; j < n; ++j) {
        if (dict.find(s.substr(i, j - i + 1)) != dict.end() && possible[j + 1]) {
          possible[i] = true;
          break;
        }
      }
    }
    return possible[0];
  }
};

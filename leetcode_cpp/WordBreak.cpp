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
    vector<bool> possible(s.size(), true);
    return dfs(s, 0, dict, possible);
  }

  bool dfs(const string &s, size_t start, unordered_set<string> &dict,
           vector<bool> &possible) {
    if (start >= s.size())
      return true;
    if (!possible[start])
      return false;
    for (size_t i = start; i < s.size(); ++i) {
      string word = s.substr(start, i - start + 1);
      if (dict.find(word) != dict.end() && dfs(s, i + 1, dict, possible)) {
        return true;
      }
    }
    return possible[start] = false;
  }
};

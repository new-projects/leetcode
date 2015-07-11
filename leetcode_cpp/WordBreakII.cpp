/**
 * Word Break II
 * Given a string s and a dictionary of words dict, add spaces in s to construct
 * a sentence where each word is a valid dictionary word.
 *
 * Return all such possible sentences.
 *
 * For example, given
 * s = "catsanddog",
 * dict = ["cat", "cats", "and", "sand", "dog"].
 *
 * A solution is ["cats and dog", "cat sand dog"].
 */
class Solution {
public:
  vector<string> wordBreak(string s, unordered_set<string> &dict) {
    vector<bool> possible(s.size(), true);
    vector<string> solutions;
    string result;
    dfs(s, 0, dict, result, solutions, possible);
    return solutions;
  }

  bool dfs(const string &s, size_t start, unordered_set<string> &dict,
           string &result, vector<string> &solutions, vector<bool> &possible) {
    if (start >= s.size()) {
      solutions.push_back(result.substr(0, result.size() - 1));
      return true;
    }
    if (!possible[start]) return false;
    possible[start] = false;
    for (size_t i = start; i < s.size(); ++i) {
      string word = s.substr(start, i - start + 1);
      if (dict.find(word) == dict.end())
        continue;
      result += word + " ";
      if (dfs(s, i + 1, dict, result, solutions, possible)) {
        possible[start] = true;
      }
      result.resize(result.size() - word.size() - 1);
    }
    return possible[start];
  }
};

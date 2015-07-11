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
    if (s.empty())
      return {};
    int n = s.size();
    vector<bool> possible(n + 1, false);
    vector<vector<int> > next(n + 1);
    possible[n] = true;
    for (int i = n - 1; i >= 0; --i) {
      for (int j = n - 1; j >= i; --j) {
        if (dict.find(s.substr(i, j - i + 1)) != dict.end() &&
            possible[j + 1]) {
          possible[i] = true;
          next[i].push_back(j + 1);
        }
      }
    }
    vector<string> solutions;
    dfs(s, 0, next, "", solutions);
    return solutions;
  }

  void dfs(const string &s, size_t start, vector<vector<int> > &next,
           string result, vector<string> &solutions) {
    if (start >= s.size()) {
      solutions.push_back(result);
      return;
    }
    string space = result.empty() ? "" : " ";
    for (int i = 0; i < next[start].size(); ++i) {
      dfs(s, next[start][i], next,
          result + space + s.substr(start, next[start][i] - start), solutions);
    }
  }
};

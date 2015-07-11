/*
Two Sum

Given an array of integers, find two numbers such that they add up to a specific
target number.

The function twoSum should return indices of the two numbers such that they add
up to the target, where index1 must be less than index2. Please note that your
returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    int n = numbers.size();
    vector<pair<int, int> > pairs;
    for (int i = 0; i < n; ++i) {
      pairs.push_back(make_pair(numbers[i], i));
    }
    sort(pairs.begin(), pairs.end());
    int l = 0, r = n - 1, index1 = 0, index2 = 0;
    while (l < r) {
      int sum = pairs[l].first + pairs[r].first;
      if (sum == target) {
        index1 = pairs[l].second;
        index2 = pairs[r].second;
        if (index1 > index2) {
          swap(index1, index2);
        }
        break;
      } else if (sum < target) {
        ++l;
      } else {
        --r;
      }
    }
    return { index1 + 1, index2 + 1 };
  }
};

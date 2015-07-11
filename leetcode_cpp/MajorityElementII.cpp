class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        if (nums.size() == 0) {
            return result;
        }
        int n1 = 0, n2 = 0;
        int c1 = 0, c2 = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == n1) {
                ++c1;
            } else if (nums[i] == n2) {
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
        
        if (c1 > n / 3) result.push_back(n1);
        if (c2 > n / 3) result.push_back(n2);
        return result;
    }
};


// generic algorithm to solve k majority element (more than int(n/k) times) problem.
// Complexity: O(nlogk)
// Space: O(k)
// The idea is to find k distinct elements and remove them all, the remaining elements
// are candidates.
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        return majorityElement(nums, 3);
    }
    
    vector<int> majorityElement(vector<int>& nums, int k) {
        vector<int> result;
        if (nums.size() == 0) {
            return result;
        }
        
        unordered_map<int, int> count;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            ++count[nums[i]];
            if (count.size() == k) {
                unordered_map<int, int>::iterator it = count.begin();
                for (; it != count.end(); ) {
                    unordered_map<int, int>::iterator curIt = it++;
                    if (--curIt->second == 0) {
                        count.erase(curIt);
                    }
                }
            }
        }
        
        unordered_map<int, int> candidateCount;
        for (int i = 0; i < n; ++i) {
            if (count.count(nums[i]) && ++candidateCount[nums[i]] == n / k + 1) {
                result.push_back(nums[i]);
            }
        }
        return result;
    }
};


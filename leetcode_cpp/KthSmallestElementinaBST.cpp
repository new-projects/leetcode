/*
 * Kth Smallest Element in a BST 
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
 *
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 *
 * Follow up:
 * What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    pair<bool, int> kthSmallestRecursive(TreeNode* root, int k) {
        if (!root) return make_pair(false, 0);
        pair<bool, int> leftRet = kthSmallestRecursive(root->left, k);
        if (leftRet.first) {
            return leftRet;
        }
        if (leftRet.second + 1 == k) {
            return make_pair(true, root->val);
        }
        pair<bool, int> rightRet = kthSmallestRecursive(root->right, k - leftRet.second - 1);
        if (rightRet.first) {
            return rightRet;
        }
        return make_pair(false, leftRet.second + rightRet.second + 1);
    }

    int kthSmallest(TreeNode* root, int k) {
        return kthSmallestRecursive(root, k).second;
    }
};

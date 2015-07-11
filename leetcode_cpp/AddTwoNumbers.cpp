/*
Add Two Numbers

You are given two linked lists representing two non-negative numbers. The digits
are stored in reverse order and each of their nodes contain a single digit. Add
the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carry = 0;
    ListNode *head = nullptr, *cur = nullptr;
    while (l1 || l2 || carry) {
      if (l1) {
        carry += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        carry += l2->val;
        l2 = l2->next;
      }
      ListNode *node = new ListNode(carry % 10);
      carry /= 10;
      if (!head) {
        cur = head = node;
      } else {
        cur->next = node;
        cur = node;
      }
    }
    return head;
  }
};

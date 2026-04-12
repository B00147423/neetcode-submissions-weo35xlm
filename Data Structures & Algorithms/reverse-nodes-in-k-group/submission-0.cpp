/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 1. Check if there are at least k nodes
        ListNode* node = head;
        int count = 0;
        while (node && count < k) {
            node = node->next;
            count++;
        }
        if (count < k) return head; // Not enough nodes to reverse

        // 2. Reverse k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* tmp = nullptr;
        count = 0;
        while (curr && count < k) {
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
            count++;
        }
        // 3. Recursively reverse the rest and connect
        head->next = reverseKGroup(curr, k);

        // 4. Return new head
        return prev;

    }
};

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

/*
    [2,4,6,8]
    dummy = 2
    temp = 4

*/
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next; // 6
        ListNode* prev = slow->next = nullptr; // 8
       while (second != nullptr) {
            ListNode* tmp = second->next; //  8
            second->next = prev; // 8
            prev = second;// 6
            second = tmp; // 8
        }
        ListNode* first = head; //2
        second = prev; // 6

        while (second != nullptr) {
            ListNode* tmp1 = first->next; //  4
            ListNode* tmp2 = second->next;//8
            first->next = second; // 6
            second->next = tmp1; // 4
            first = tmp1;// 4
            second = tmp2; // 8
        }
    }
};

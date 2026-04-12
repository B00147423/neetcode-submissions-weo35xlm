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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next;
        ListNode* prev = slow->next = nullptr;


       while (second != nullptr) {
            ListNode* tmp = second->next;
            second->next = prev;
            prev = second;
            second = tmp; 
        }
        ListNode* currHead = head;
        second = prev;

        while (second != nullptr) {
            ListNode* tmp1 = currHead->next; 
            ListNode* tmp2 = second->next;
            currHead->next = second;
            second->next = tmp1; 
            currHead = tmp1;
            second = tmp2; 
        }
    }
};
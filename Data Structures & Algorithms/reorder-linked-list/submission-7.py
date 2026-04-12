# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        slow, fast = head, head.next

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        # 2 → 4 → None
        second = slow.next # 6 → 8 → None
        slow.next = None #  → None
        prev = None # prev → None

        while second:
            tmp = second.next # 8 tmp = 8
            second.next = prev #  6-> = None
            prev = second # 6
            second = tmp # 8
            #tmp = second.next #  None
            #second.next = prev # 8 -> 6
            #prev = second # 8
            #second = tmp # None
            #8->6->NONE

        first = head  # 2,4
        second = prev # prev = 8->6

        while second:
            tmp1, tmp2 = first.next, second.next
            #tmp1 = 4
            #tmp2 = 6
            first.next = second
            #2 → 8
            second.next = tmp1
            #8 → 4
            first, second = tmp1, tmp2
            #first = 4
            #second = 6

            #tmp1 = None
            #tmp2 = None
            #first.next = second 4 → 6
            #second.next = tmp1 6 → None

            #first = tmp1 first = None
            #second = tmp2 second = None
            





# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        '''
head = [1,2,3,4], n = 2


INITIALLY:
l = 0
r = 1
        0->1->2->3->4->none
        ^  ^
        l  r

AFTER LOOP: n times
R = 3
L = 0
        0->1->2->3->4->none
        ^        ^
        l        r

AFTER MVOING RIGHT TP NoNE: 
R = none
L = 2
        0->1->2->3->4->none
              ^        ^
              l        r
        
skipping Nth node 
(->3) removed

dummy = 0
l = 4
r = none
        0->1->2->4->none
                 ^    ^
                 l    r


right = at node 3
mvoe slow until right is at the end so 

end up right = none
left = node 2

then skip over ndoe to remove so 

0->1->2->3->4->none
        ^        ^
        l        r

left 2->4->

0->1->2->4-> 

        '''

        dummy = ListNode(0, head)
        left = dummy
        right = head

        while n > 0:
            right = right.next
            n -= 1

        while right:
            left = left.next
            right = right.next
        

        left.next = left.next.next 
        return dummy.next

        

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodeToInt(self, l1: ListNode, base: int = 10) -> int:
        ret = 0
        mul = 1
        
        while l1:
            ret += l1.val * mul
            mul *= base
            l1 = l1.next
            
        return ret

    def intToNode(self, val: int, base: int = 10) -> ListNode:
        dummy = ListNode(0)
        prev = dummy
        
        if val == 0:
            return ListNode(0)
            
        while val > 0:
            node = ListNode(val % base)
            val //= base
            
            prev.next = node
            prev = node

        return dummy.next

    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        return self.intToNode(self.nodeToInt(l1) + self.nodeToInt(l2))
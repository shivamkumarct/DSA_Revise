// 142. LinkedList Cycle 2
// Time Complexity O(N)
// Space Complexity O(1)

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next){
            fast= fast->next->next;
            slow = slow->next;

            if(fast==slow){
                slow = head;
                while(fast!=slow){
                    fast=fast->next;
                    slow=slow->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
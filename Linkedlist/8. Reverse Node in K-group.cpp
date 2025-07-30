// 25. Reverse Node in K-Group 
// Time Complexity O(N)
// Space Complexity O(1)

class Solution {
public:
    int length(ListNode* head){
        int count=0;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = length(head);
        if(k>len) return head;

        //Step A: reverse first k nodes of LL
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = curr -> next;
        int count = 0;

        while(count < k) {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
            count++;
        }

        //Step B: recursive call
        if(forward != NULL) {
            // we still have nodes left to reverse
            head -> next = reverseKGroup(forward, k);
        }

        //step C: return head of the modified LL
        return prev;
    }
};
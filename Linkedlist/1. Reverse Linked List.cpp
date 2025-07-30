// 206. Reverse Linked List
// Recurisive Way
// Time Complexity O(N)
// Space Complexity O(1)

class Solution {
public:
    ListNode* reverse(ListNode* &prev, ListNode* &curr){
        if(curr == NULL)
            return prev;

        // 1 case solve
        ListNode* forward = curr->next;
        curr->next = prev;

        return reverse(curr, forward);
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        return reverse(prev, head);
    }
};


// Linear way
// Time Complexity O(N)
// Space Complexity O(1)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};
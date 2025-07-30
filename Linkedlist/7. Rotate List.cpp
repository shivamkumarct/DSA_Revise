// 61. Rotate list
// Time Complexity O(N)
// Space Complexity O(1)

class Solution {
public:
    int getLen(ListNode* head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;

        int len = getLen(head);
        int actualRotateK = (k % len);
        
        if(actualRotateK == 0) return head;

        int newLastNodePos = len - actualRotateK - 1;
        ListNode* newLastNode = head;

        for(int i=0; i<newLastNodePos; i++){
            newLastNode = newLastNode->next;
        }

        ListNode* newHead = newLastNode->next;
        newLastNode->next = NULL;

        ListNode* it = newHead;
        while(it->next != NULL){
            it = it->next;
        }
        it->next = head;
        return newHead;
    }
};
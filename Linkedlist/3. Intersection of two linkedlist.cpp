// 160. Intersection of two LinkedList
// Time Complexity O(N)
// Space Complexity O(1)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;

        while(a->next && b->next){
            if(a == b) return a;

            a = a->next;
            b = b->next;
        }
        if(a->next == NULL && b->next == NULL && a != b) return NULL;
        
        if(a->next == NULL){
            // b is bigger list of equal
            // now find size how much bigger
            int blen = 0;
            while(b->next){
                blen++;
                b = b->next;
            }
            while(blen--){
                headB = headB->next;
            }
        }
        else{
            // A is bigger list or equal
            // now find size how much bigger
            int alen = 0;
            while(a->next){
                alen++;
                a = a->next;
            }
            while(alen--){
                headA = headA->next;
            }
        }
        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
// 148. Sort list
// Time Complexity O(NLogN)
// Space Complexity O(1)

class Solution {
public:
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;

        while(left && right) {
            if(left->val <= right->val) {
                temp->next = left;
                left = left->next;
            }
            else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }

        temp->next = left ? left : right;

        return ans->next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* mid = findMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;

        left = sortList(left);
        right = sortList(right);

        ListNode* ans = merge(left, right);
        return ans;
    }
};
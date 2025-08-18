// 23. Merge K sorted Lists
// Time Complexity O()
// Space Complexity O()

class compare{
public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        
        int k = lists.size();
        if(k == 0) return NULL;

        // insert first element of every linkedList
        for(int i=0; i<k; i++)
            if(lists[i]) minHeap.push(lists[i]);

        ListNode* head = NULL; 
        ListNode* tail = NULL;

        while(!minHeap.empty()){
            ListNode* temp = minHeap.top();
            minHeap.pop();

            if(!head) { // temp is the first element of the answer
                head = tail = temp;
            }
            else{
                tail->next = temp;
                tail = temp;
            }
            if(tail->next) minHeap.push(tail->next); 
        }
        return head;
    }
};
// 138. Copy list with random pointer
// Time Complexity O(N)
// Space Complexity O(1)

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return 0;

        // step1 clone A->A'
        Node* it = head;
        while(it){
            Node* cloneNode = new Node(it->val);
            cloneNode->next = it->next;
            it->next = cloneNode;
            it = it->next->next;
        }

        // step2 assingn random links
        it= head;
        while(it){
            Node* cloneNode = it->next;
            cloneNode->random = it->random ? it->random->next : nullptr;
            it = it->next->next; 
        }

        // step3 detach A' from A
        it=head;
        Node* cloneHead = it->next;
        while(it){
            Node* cloneNode = it->next;
            it->next = it->next->next;
            if(cloneNode->next){
                cloneNode->next = cloneNode->next->next;
            }
            it = it->next;
        }
        return cloneHead;
    }
};
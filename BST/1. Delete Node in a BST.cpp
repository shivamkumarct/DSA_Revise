// 450. Delete Node in a BST
// Time Complexity O()
// Space Complexity O()

class Solution {
public:
    int maxVal(TreeNode* root){
        if(root == NULL) return -1;

        TreeNode* temp = root;
        while(temp->right) temp = temp->right;

        return temp->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        // base case
        if(!root) return NULL;

        if(root->val == key) { // 4 case
            if(root->left == NULL && root->right == NULL) // leaf node
                return NULL;

            else if(root->left == NULL && root->right != NULL) // olny right present
                return root->right;

            else if(root->left != NULL && root->right == NULL) // only left present
                return root->left;

            else { // both child 
                int inorderPre = maxVal(root->left); // find inorder predesesor
                
                root->val = inorderPre; // replace inorderPre with root->data
                
                // delete inorderPre from left subtree
                root->left = deleteNode(root->left, inorderPre);
                return root;
            }
        }
        else if(root->val > key)
            root->left = deleteNode(root->left, key);

        else if(root->val < key)
            root->right = deleteNode(root->right, key);

        return root;
    }
};
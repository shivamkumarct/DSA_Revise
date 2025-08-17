// 235. Lowest Common Ancestor of a Binary Search Tree
// Time Complexity O(longN) verify
// Space Complexity O(1)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if(root == NULL)  return NULL;

        if(p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
            
        if(p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);

        return root;
    }
};
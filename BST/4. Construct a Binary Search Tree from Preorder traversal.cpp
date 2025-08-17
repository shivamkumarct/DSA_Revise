// 1008. Construct Binary Search Tree from Preorder traversal
// Time Complexity O(N)
// Space Complexity O(1)

class Solution {
public:
    TreeNode* build(vector<int>& preorder, int min, int max, int& i){
        if(i >= preorder.size()) return NULL;

        TreeNode* root = NULL;
        if(min < preorder[i] && preorder[i] < max){
            root = new TreeNode(preorder[i++]);
            root->left = build(preorder, min, root->val, i);
            root->right = build(preorder, root->val, max, i);
        } 
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int min = INT_MIN, max = INT_MAX, i = 0;

        return build(preorder, min, max, i);
    }
};
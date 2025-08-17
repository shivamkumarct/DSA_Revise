// 230. Kth Smallest Element in a BST
// Time Complexity O(N)
// Space Complexity O(1)

class Solution {
public:
    int kthSmallest(TreeNode* root, int &k) {
        if(!root) return -1;

        int ans = kthSmallest(root->left, k);
        if(ans != -1) return ans;

        if(--k == 0) return root->val;

        return kthSmallest(root->right, k);
    }
};
// 543. Diameter of Binary tree
// Time Complexity O()
// Space Complexity O()

class Solution {
public:
    int height(TreeNode* root) {
        if(!root) return 0;

        return 1 + max(height(root->left), height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int throughRoot = height(root->left) + height(root->right);

        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);

        return max(throughRoot, max(leftDiameter, rightDiameter));
    }
};
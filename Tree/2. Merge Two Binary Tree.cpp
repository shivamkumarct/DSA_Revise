// 617. Merge Two Binary Trees
// Time Complexity O()
// Space Complexity O()


class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL) return NULL;
        if (root2 != NULL){
            if (root1 == NULL){
                root1 = root2;
                root2 = NULL;
            } else {
                root1->val+=root2->val;
            }
        }
        root1->left = mergeTrees(root1->left,root2==NULL? NULL: root2->left);
        root1->right = mergeTrees(root1->right,root2==NULL ? NULL : root2->right);
        return root1;
    }
};
// 437. Path Sum 3
// Time Complexity O()
// Space Complexity O()

class Solution {
public:
    int ans = 0;
    void pathFromOneRoot(TreeNode* root, long long sum){
        if(!root) return;

        if(sum == root->val) 
            ans++;

        pathFromOneRoot(root->left, sum - root->val);
        pathFromOneRoot(root->right, sum - root->val);
    }
    int pathSum(TreeNode* root, long long targetSum) {
        if(root){
            pathFromOneRoot(root, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return ans;
    }
};
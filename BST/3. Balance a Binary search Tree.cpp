// 1382. Balance a Binary Search Tree
// Time Complexity O(N)
// Space Complexity O(N)

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& nums){
        // base case
        if(!root) return;

        //LNR
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
    TreeNode* solve(vector<int>& nums, int s, int e){
        if(s>e) return NULL;
        int mid = (s+e)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = solve(nums, s, mid-1);
        root->right = solve(nums, mid+1, e);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);

        return solve(nums, 0, nums.size()-1);
    }
};
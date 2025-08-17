// 106. Construct Binary Tree from Inorder and Postorder Traversal
// Time Complexity O(N)
// Space Complexity O(N)

class Solution {
public:
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int n, int& postIndex, int inorderStart, int inorderEnd, unordered_map<int, int>& mp){
        // base case
        if(postIndex < 0 || inorderStart > inorderEnd) return NULL;

        // Step A
        int element = postorder[postIndex--];
        TreeNode* root = new TreeNode(element);
        int pos = mp[element];

        // step B -> solve root->right
        root->right = solve(inorder, postorder, n, postIndex, pos+1, inorderEnd, mp);
        // step C -> solve root->left
        root->left = solve(inorder, postorder, n, postIndex, inorderStart, pos-1, mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int postIndex = n-1;
        int inorderStart = 0, inorderEnd = n-1;

        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) mp[inorder[i]] = i;

        return solve(inorder, postorder, n, postIndex, inorderStart, inorderEnd, mp);
    }
};
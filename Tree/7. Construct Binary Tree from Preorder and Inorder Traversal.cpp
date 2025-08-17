// 105. Construct Binary Tree from Preorder and Inorder Traversal
// Time Complexity O(N)
// Space Complexity O(N)

class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int n, int& preIndex, int inorderStart, int inorderEnd, unordered_map<int, int>& mp){
        // base case
        if(preIndex >= n || inorderStart > inorderEnd) return NULL;

        // Step A
        int element = preorder[preIndex++];
        TreeNode* root = new TreeNode(element);
        int pos = mp[element];

        // step B -> solve root->left
        root->left = solve(preorder, inorder, n, preIndex, inorderStart, pos-1, mp);
        // step c -> solve root->right
        root->right = solve(preorder, inorder, n, preIndex, pos+1, inorderEnd, mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int preIndex = 0;
        int inorderStart = 0, inorderEnd = n-1;

        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) mp[inorder[i]] = i;

        return solve(preorder, inorder, n, preIndex, inorderStart, inorderEnd, mp);
    }
};
// 987. Vertical Order Traversal of a Binary Tree
// Time Complexity O()
// Space Complexity O()


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, int>>> q; // {node, (row, col)}
        q.push({root, {0, 0}});

        map<int, map<int, multiset<int>>> mp;  // col -> {row -> [x, y, z...]}
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            
            TreeNode*& node = p.first;
            int row = p.second.first;
            int col = p.second.second;

            mp[col][row].insert(node->val);

            if(node->left)
                q.push({node->left, {row + 1, col - 1}});
            if(node->right)
                q.push({node->right, {row + 1, col + 1}});
        }

        // store the final order in ans vector
        for(auto it:mp){
            auto& colMap = it.second;
            vector<int> vLine;
            for(auto colMapIt:colMap){
                auto& mset = colMapIt.second;
                vLine.insert(vLine.end(), mset.begin(), mset.end());
            }
            ans.push_back(vLine);
        }
        return ans;
    }
};
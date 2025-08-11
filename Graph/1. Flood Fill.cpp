// 733. Flood Fill
// Time Complexity O(M*N)
// Space Complexity O(M*N)

class Solution {
public:
    void dfs(int x, int y, int oldColor, int newColor, map<pair<int, int>, bool>& vis, vector<vector<int>>& ans){
        vis[{x, y}] = true;
        ans[x][y] = newColor;

        vector<pair<int, int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for(auto& dir:direction) {
            int newX = x + dir.first;
            int newY = y + dir.second;

            if(newX>=0 && newX<ans.size() && newY>=0 && newY<ans[0].size() && !vis[{newX, newY}] && ans[newX][newY]==oldColor){
                dfs(newX, newY, oldColor, newColor, vis, ans);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        map<pair<int, int>, bool> vis;
        vector<vector<int>> ans = image;
        dfs(sr, sc, oldColor, color, vis, ans);
        return ans;
    }
};
// G. Rat in a maze
// Time Complexity O(4^N)
// Space Complexity O(4^N)

class Solution {
  public:
    int n;
    void solve(vector<vector<int>>& maze, int x, int y, string output, vector<string>& ans) {
        if(x == n-1 && y == n-1) {
            ans.push_back(output);
            return;
        }
        
        maze[x][y] = -1;
        
        // D -> x+1, y
        if(x+1 < n && maze[x+1][y] == 1) {
            solve(maze, x+1, y, output + 'D', ans);
        }
        
        // U -> x-1, y
        if(x-1 >= 0 && maze[x-1][y] == 1) {
            solve(maze, x-1, y, output + 'U', ans);
        }
        
        // R -> x, Y+1
        if(y+1 < n && maze[x][y+1] == 1) {
            solve(maze, x, y+1, output + 'R', ans);
        }
        
        // L -> x, Y-1
        if(y-1 >= 0 && maze[x][y-1] == 1) {
            solve(maze, x, y-1, output + 'L', ans);
        }
        
        maze[x][y] = 1;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        n = maze.size();
        vector<string> ans;
        string output = "";
        
        if (maze[0][0] == 0 || maze[n-1][n-1] == 0) 
            return ans;
        
        solve(maze, 0, 0, output, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
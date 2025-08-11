// 200. Number of Islands
// Time Complexity O(M*N)
// Space Complexity O(M*N)

class Solution {
public:
    void bfs(map< pair<int, int>, bool>& visited, int row, int col, vector<vector<char>>& grid){
        queue<pair<int, int>> q;
        
        q.push({row, col});
        visited[{row, col}] = true;

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};
            // it can move in 4 direction 
            for(int i = 0; i < 4; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && !visited[{newX, newY}] && grid[newX][newY] == '1'){
                    q.push({newX, newY});
                    visited[{newX, newY}] = true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        map< pair<int, int>, bool> visited;
        int count = 0;

        for(int row=0; row<grid.size(); row++){
            for(int col=0; col<grid[0].size(); col++){
                if(!visited[{row, col}] && grid[row][col] == '1'){
                    bfs(visited, row, col, grid);
                    count++;
                }
            }
        }
        return count;
    }
};
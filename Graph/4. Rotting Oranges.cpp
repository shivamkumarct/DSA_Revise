// 994. Rotting Oranges
// Time Complexity O(M*N)
// Space Complexity O(M*N)

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> arr = grid;
        int count = 0;
        int ansTime = 0;
        int m = grid.size(), n = grid[0].size();

        // insert all rotten oranges in queue
        for(int row =0; row<m; row++){
            for(int col=0; col<n; col++){
                if(grid[row][col] == 2) // rotten oranges found
                    q.push({{row, col}, 0});
            }
        }

        while(!q.empty()){
            auto fNode = q.front();
            q.pop();
            int x = fNode.first.first;
            int y = fNode.first.second;
            int time = fNode.second;

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for(int i=0; i<4; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(newX >= 0 && newX < m && newY >= 0 && newY < n && arr[newX][newY] == 1){
                    q.push({{newX, newY}, time+1});
                    ansTime = max(ansTime, time+1);
                    // mark rotten
                    arr[newX][newY] = 2;
                }
            }
        }

        // check for fresh oranges
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(arr[i][j] == 1) return -1;   
            }
        }
        return ansTime;
    }
};
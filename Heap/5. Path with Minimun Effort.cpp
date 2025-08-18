// 1631. Path with Minimum Effort
// Time Complexity O()
// Space Complexity O()

class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()) {
            int d = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x == m-1 && y == n-1) return d;

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for(int i = 0; i < 4; i++) {
                int newx = x + dx[i];
                int newy = y + dy[i];

                if(newx >= 0 && newx < m && newy >= 0 && newy < n ) {
                    int newDiff = max(d, abs(heights[x][y] - heights[newx][newy]));

                    if(newDiff < dist[newx][newy]) {
                        dist[newx][newy] = newDiff;
                        pq.push({newDiff, {newx, newy}});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};
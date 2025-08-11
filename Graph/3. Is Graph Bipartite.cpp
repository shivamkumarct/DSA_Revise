// 785. Is Graph Bipartite
// Time Complexity O(N+E)
// Space Complexity O(N)

class Solution {
public:
    bool dfs(int u, vector<vector<int>>& graph, vector<int>& color, int currCol) {
        color[u] = currCol;

        for(int &v:graph[u]) {
            if(color[v] == currCol) 
                return false;

            if(color[v] == -1 && !dfs(v, graph, color, 1 - currCol))
                return false; 
        }
        return true;
    }

    bool bfs(int u, vector<vector<int>>& graph, vector<int>& color, int currCol) {
        queue<int> q;
        q.push(u);
        color[u] = currCol;

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            
            for(int v:graph[u]) {
                if(color[v] == color[u]) return false;

                if(color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        // for(int i = 0; i < n; i++) {
        //     if(color[i] == -1 && !dfs(i, graph, color, 1))
        //         return false;
        // }

        for(int i = 0; i < n; i++) {
            if(color[i] == -1 && !bfs(i, graph, color, 1))
                return false;
        }
        return true;
    }
};
// 1319. Number of Operation to make network connected
// Time Complexity O()
// Space Complexity O()

// Using DFS or BFS
class Solution {
public:
    void dfs(int u, unordered_map<int, vector<int>>& adj, vector<bool>& visited) {
        visited[u] = true;

        for(int &v:adj[u] ) {
            if(!visited[v]) dfs(v, adj, visited);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;

        unordered_map<int, vector<int>> adj;
        for(auto vec:connections) {
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }

        vector<bool> visited(n, false);
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(i, adj, visited);
                count++;
            }
        }
        return count-1;
    }
};


// Using DSU
// Time Complexity O()
// Space Complexity O()
class Solution {
public:
    int find(int x, vector<int>& parent) {
        if(x == parent[x]) return x;

        return parent[x] = find(parent[x], parent);
    }
    void uni(int x, int y, vector<int>& parent, vector<int>& rank) {
        int xParent = find(x, parent);
        int yParent = find(y, parent);

        if(xParent == yParent) return;

        if(rank[xParent] < rank[yParent]) {
            parent[xParent] = yParent;
        }
        else if(rank[xParent] > rank[yParent]) {
            parent[yParent] = xParent;
        }
        else {
            parent[xParent] = yParent;
            rank[yParent] += 1;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;

        vector<int>parent(n);
        for(int i = 0; i < n; i++) parent[i] = i;

        vector<int> rank(n, 0);

        int count = n;
        for(auto &v:connections) {
            if(find(v[0], parent) != find(v[1], parent)) {
                count--;
                uni(v[0], v[1], parent, rank);
            }
        }
        return count-1;
    }
};
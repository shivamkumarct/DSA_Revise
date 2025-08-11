// 210. Course Schedule 2
// Time Complexity O()
// Space Complexity O()

class Solution {
private:
    vector<int> topoSort(int n, unordered_map<int, vector<int>>& adj) {
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++) {
            for(int &v:adj[i]) indegree[v]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> ans;
        while(!q.empty()) {
            int u = q.front();
            ans.push_back(u);
            q.pop();

            for(int &v:adj[u]) {
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }
        return ans.size() == n ? ans : vector<int>{};
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for(auto &vec:prerequisites) {
            adj[vec[1]].push_back(vec[0]);
        }
        return topoSort(numCourses, adj);
    }
};
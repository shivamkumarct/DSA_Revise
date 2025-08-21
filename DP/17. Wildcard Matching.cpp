// 44. Wildcard Matching
// Time Complexity O()
// Space Complexity O()

class Solution {
public:
    bool solve(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        if(i < 0 && j < 0) return true;
        if(i >= 0 && j < 0) return false;
        if(i < 0 && j >= 0) {
            for(int k = 0; k <= j; k++) {
                if(p[k] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j] || p[j] == '?') return dp[i][j] = solve(i-1, j-1, s, p, dp);
        else if(p[j] == '*') return dp[i][j] = (solve(i-1, j, s, p, dp) || solve(i, j-1, s, p, dp));
        else return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m-1, n-1, s, p, dp);
    }
};
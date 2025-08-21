// 1130. Minimum cost tree from leaf node
// Time Complexity O()
// Space Complexity O()

class Solution {
public:
    int recursion(vector<int>& arr, map<pair<int, int>, int>& maxi, int left, int right){
        // base case
        if(left == right) return 0;

        int ans = INT_MAX;

        for(int i=left; i<right; i++){
            ans = min(ans, maxi[{left, i}]*maxi[{i+1, right}] 
                      + recursion(arr, maxi, left, i)
                      + recursion(arr, maxi, i+1, right));
        }
        return ans;
    }

    int memoization(vector<int>& arr, map<pair<int, int>, int>& maxi, int left, int right, vector<vector<int>>& dp){
        // base case
        if(left == right) return 0;

        if(dp[left][right] != -1)
            return dp[left][right];

        int ans = INT_MAX;

        for(int i=left; i<right; i++){
            ans = min(ans, maxi[{left, i}]*maxi[{i+1, right}] 
                      + memoization(arr, maxi, left, i, dp)
                      + memoization(arr, maxi, i+1, right, dp));
        }
        dp[left][right] = ans;
        return dp[left][right];
    }
    
    int tabulation(vector<int>& arr, map<pair<int, int>, int>& maxi){
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int left=n-1; left>=0; left--){
            for(int right=0; right<=n-1; right++){
                if(left >= right)
                    continue;
                else{
                    int ans = INT_MAX;

                    for(int i=left; i<right; i++){
                        ans = min(ans, maxi[{left, i}]*maxi[{i+1, right}] 
                                + dp[left][i]
                                + dp[i+1][right]);
                    }
                    dp[left][right] = ans;
                }
            }
        }
        return dp[0][n-1];
    }

    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        map<pair<int, int>, int> maxi;
        for(int i=0; i<n; i++){
            maxi[{i, i}] = arr[i];
            for(int j=i+1; j<n; j++){
                maxi[{i,j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }

        // int ans = recursion(arr, maxi, 0, n-1);

        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // int ans = memoization(arr, maxi, 0, n-1, dp);

        int ans = tabulation(arr, maxi);
        return ans;
    }
};
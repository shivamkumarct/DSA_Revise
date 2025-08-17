// 1155. Number of Dice rolls with target sum
// Time Complexity O()
// Space Complexity O()

class Solution {
public:
    int MOD = 1000000007;
    int recursion(int n, int k, int target){
        //base case
        if(n<0) return 0;
        if( n == 0 && target != 0) return 0;
        if( n != 0 && target == 0) return 0;
        if( n == 0 && target == 0) return 1;

        int ans = 0;
        for(int i=1; i<=k; i++){
            ans += recursion(n-1, k, target - i);
        }
        return ans;
    }

    int memoization(int n, int k, int target, vector<vector<int>>& dp){
        //base case
        // if(n<0) return 0;
        if(target < 0) return 0;
        if( n == 0 && target != 0) return 0;
        if( n != 0 && target == 0) return 0;
        if( n == 0 && target == 0) return 1;

        if(dp[n][target] != -1)
            return dp[n][target];

        int ans = 0;
        for(int i=1; i<=k; i++){
            ans = ans%MOD;
            ans += memoization(n-1, k, target - i, dp);
        }
        dp[n][target] = ans%MOD;
        return dp[n][target];
    }

    int tabulation(int n, int k, int target){
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        dp[0][0] = 1;

        for(int index=1; index<=n; index++){
            for(int t=1; t<=target; t++){
                int ans = 0;
                for(int i=1; i<=k; i++){
                    int recAns = 0;
                    if(t-i >=0)
                        recAns = dp[index-1][t - i];
                    ans = (ans%MOD + recAns%MOD)%MOD;
                }
                dp[index][t] = ans%MOD;
            }
        }
        return dp[n][target];
    }

    int spaceOptimization(int n, int k, int target){
        vector<int> prev(target+1, 0);
        vector<int> curr(target+1, 0);

        prev[0] = 1;

        for(int index=1; index<=n; index++){
            for(int t=1; t<=target; t++){
                int ans = 0;
                for(int i=1; i<=k; i++){
                    int recAns = 0;
                    if(t-i >=0)
                        recAns = prev[t - i];
                    ans = (ans%MOD + recAns%MOD)%MOD;
                }
                curr[t] = ans%MOD;
            }
            //sift
            prev = curr;
        }
        return prev[target];
    }
    
    int numRollsToTarget(int n, int k, int target) {
        // return recursion(n, k, target);

        // vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        // return memoization(n, k, target, dp);

        // return tabulation(n, k, target);

        return spaceOptimization(n, k, target);
    }
};